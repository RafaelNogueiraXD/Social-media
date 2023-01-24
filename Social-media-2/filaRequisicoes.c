// funcoes da fila de requisições
#include "perfil.c"

typedef struct filaRequisicoes
{
    int id;
    struct filaRequisicoes *proximo;
} Fila;

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

Fila *aceitaSolicitacao(Fila *pilha, User *usuarioEspecifico, User *usuarios)
{
    if (pilha != NULL)
    {
        User *usuAux = NULL;
        User *proximoAux = NULL;
        User *amigo=NULL;

        usuAux = procuraUserId(usuarios, pilha->id);

        amigo=(User *)malloc(sizeof(User));
        amigo->perfilDoUsuario=(Perfil *)malloc(sizeof(Perfil));
        amigo->perfilDoUsuario->nome=(char *)malloc(sizeof(char) * 150);

        if (usuarioEspecifico->listaDeAmigos == NULL)
        {
            usuarioEspecifico->listaDeAmigos = amigo;
            usuarioEspecifico->listaDeAmigos->proximo=NULL;
        }

        usuarioEspecifico->listaDeAmigos->perfilDoUsuario->id=usuAux->perfilDoUsuario->id;
        usuarioEspecifico->listaDeAmigos->perfilDoUsuario->idade=usuAux->perfilDoUsuario->idade;
        usuarioEspecifico->listaDeAmigos->perfilDoUsuario->nome=usuAux->perfilDoUsuario->nome;

        usuarioEspecifico->listaDeAmigos = usuAux;
        usuarioEspecifico->listaDeAmigos->proximo = proximoAux;
        removeSolicitacao(pilha);
    }
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