// funcoes da fila de requisições
#include "perfil.c"

typedef struct filaRequisicoes
{
    int id;
    struct filaRequisicoes *proximo;
} Fila;


int numSolicitacoes(Fila *pilha){

    Fila *pilhaux=pilha;
    int contador=0;

    if(pilhaux==NULL)return NULL;

    while(pilhaux!=NULL){
        contador++;
        pilhaux= pilhaux->proximo;
    }

    return contador;
}


int verificaFila(int id, Fila *pilha)
{
    Fila *pilhaux = pilha;

    while (pilhaux != NULL)
    {
        printf("\n\n\nid:%d == %d\n\n\n",pilhaux->id,id);
        if (pilhaux->id == id){
            printf("retornou 1");
            return 1;
        }
        else
            pilhaux = pilhaux->proximo;
    }
    printf("retornou 0");
    return 0;
}

Fila *enviaSolicitacao(Fila *pilha, int id)
{
    if (pilha == NULL)
    {
        Fila *filaReq = (Fila *)malloc(sizeof(Fila));
        filaReq->id = id;
        filaReq->proximo = NULL;
        return filaReq;
    }
    else
    {
        Fila *filaReq = (Fila *)malloc(sizeof(Fila));
        filaReq->id = id;
        filaReq->proximo = pilha;
        return filaReq;
    }
}

Fila *removeSolicitacao(Fila *pilha)
{
    if (pilha != NULL)
    {
        Fila *proximoAux = pilha->proximo;
        free(pilha);
        return proximoAux;
    }
    else
        return NULL;
}

Fila *rejeitaTodos(Fila *pilha, User *usuarioEspecifico, User *usuarios)
{

    while (pilha != NULL)
    {
        pilha = removeSolicitacao(pilha);
    }
    return pilha;
}

Fila *aceitaSolicitacao(Fila *pilha, User *usuarioEspecifico, User *usuarios)
{
    if (pilha != NULL)
    {

        User *usuAux = NULL;
        User *proximoAux1 = NULL, *proximoAux2 = NULL;
        User *amigo1 = NULL, *amigo2 = NULL;

        usuAux = procuraUserId(usuarios, pilha->id);

        if (usuAux == NULL)
            return NULL;

        amigo1 = (User *)malloc(sizeof(User));
        amigo1->perfilDoUsuario = (Perfil *)malloc(sizeof(Perfil));
        amigo1->perfilDoUsuario->nome = (char *)malloc(sizeof(char) * 150);

        amigo2 = (User *)malloc(sizeof(User));
        amigo2->perfilDoUsuario = (Perfil *)malloc(sizeof(Perfil));
        amigo2->perfilDoUsuario->nome = (char *)malloc(sizeof(char) * 150);

        if (usuarioEspecifico->listaDeAmigos == NULL)
        {
            usuarioEspecifico->listaDeAmigos = amigo1;
            usuarioEspecifico->listaDeAmigos->proximo = NULL;
        }
        else
        {

            proximoAux1 = usuarioEspecifico->listaDeAmigos;
            usuarioEspecifico->listaDeAmigos = amigo1;
            usuarioEspecifico->listaDeAmigos->proximo = proximoAux1;
        }

        if (usuAux->listaDeAmigos == NULL)
        {
            usuAux->listaDeAmigos = amigo2;
            usuAux->listaDeAmigos->proximo = NULL;
        }
        else
        {

            proximoAux2 = usuAux->listaDeAmigos;
            usuAux->listaDeAmigos = amigo2;
            usuAux->listaDeAmigos->proximo = proximoAux2;
        }

        usuarioEspecifico->listaDeAmigos->perfilDoUsuario->id = usuAux->perfilDoUsuario->id;
        usuarioEspecifico->listaDeAmigos->perfilDoUsuario->idade = usuAux->perfilDoUsuario->idade;
        usuarioEspecifico->listaDeAmigos->perfilDoUsuario->nome = usuAux->perfilDoUsuario->nome;


        usuAux->listaDeAmigos->perfilDoUsuario->id = usuarioEspecifico->perfilDoUsuario->id;
        usuAux->listaDeAmigos->perfilDoUsuario->idade = usuarioEspecifico->perfilDoUsuario->idade;
        usuAux->listaDeAmigos->perfilDoUsuario->nome = usuarioEspecifico->perfilDoUsuario->nome;

        pilha = removeSolicitacao(pilha);
        usuarioEspecifico->amigosPendentes = pilha;
        return usuarioEspecifico->amigosPendentes;
    }
    else
        return NULL;
}

Fila *aceitaTodas(Fila *pilha, User *usuarioEspecifico, User *usuarios)
{
    while (pilha != NULL)
    {
        pilha = aceitaSolicitacao(pilha, usuarioEspecifico, usuarios);
    }
    return pilha;
}

void imprimirSolicitacao(Fila *pilha, User *usuarios)
{
    if (pilha == NULL)
        printf("\n\nFim da lista\n\n");
    else
    {
        Perfil *usuAux = NULL;
        usuAux = procuraUserId2(usuarios, pilha->id);
        if (usuAux == NULL)
            printf("\n\t o usuario %d nao esta mais presente.", pilha->id);
        else
            imprimirPerfil(usuAux);
        return imprimirSolicitacao(pilha->proximo, usuarios);
    }
}