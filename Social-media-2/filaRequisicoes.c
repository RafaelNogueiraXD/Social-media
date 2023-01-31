// funcoes da fila de requisições
#include "perfil.c"
// cria a struct responsavel pelas Solicitacoes de amizades
typedef struct filaRequisicoes
{
    int id;
    struct filaRequisicoes *proximo;
} Fila;

// retorna o numero de solicitacoes
int numSolicitacoes(Fila *row)
{

    Fila *rowAux = row;
    int contador = 0;

    if (rowAux == NULL)
        return 0;

    while (rowAux != NULL)
    {
        contador++;
        rowAux = rowAux->proximo;
    }

    return contador;
}

// funcao responsavel para verificar se um determinado ID existe na lista
int verificaFila(int id, Fila *row)
{
    Fila *rowAux = row;

    while (rowAux != NULL)
    {
        if (rowAux->id == id)
            return 1;
        else
            rowAux = rowAux->proximo;
    }
    return 0;
}
// funcao responsavel por enviar as solicitacoes
Fila *enviaSolicitacao(Fila *row, int id)
{
    if (row == NULL)
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
        filaReq->proximo = row;
        return filaReq;
    }
}
// funcao responsavel por remover uma solicitacao
Fila *removeSolicitacao(Fila *row)
{
    if (row != NULL)
    {
        Fila *proximoAux = row->proximo;
        free(row);
        return proximoAux;
    }
    else
        return NULL;
}
// funcao responsavel por remover todas as solicitacoes
Fila *rejeitaTodos(Fila *row, User *usuarioEspecifico, User *usuarios)
{

    while (row != NULL)
    {
        row = removeSolicitacao(row);
    }
    return row;
}
// funcao responsavel por aceitar todas solicitacoes
Fila *aceitaSolicitacao(Fila *row, User *usuarioEspecifico, User *usuarios)
{
    if (row != NULL)
    {

        User *usuAux = NULL;
        User *proximoAux1 = NULL, *proximoAux2 = NULL;
        User *amigo1 = NULL, *amigo2 = NULL;
        // primeiro acha o usuario no sistema por meio da func procuraUserId()
        usuAux = procuraUserId(usuarios, row->id);

        if (usuAux == NULL)
            return NULL;
        // aloca os ponteiros para a insercao dos novos amigos
        amigo1 = (User *)malloc(sizeof(User));
        amigo1->perfilDoUsuario = (Perfil *)malloc(sizeof(Perfil));
        amigo1->perfilDoUsuario->nome = (char *)malloc(sizeof(char) * 150);

        amigo2 = (User *)malloc(sizeof(User));
        amigo2->perfilDoUsuario = (Perfil *)malloc(sizeof(Perfil));
        amigo2->perfilDoUsuario->nome = (char *)malloc(sizeof(char) * 150);
        /*
            Se o usuario nao tiver amigos sera adicionado a struct arressem alocada
            para dentro da lista de amigos dele, caso o contrario o novo
            sera colacodo  em 1 primeiro da lista de amigos
        */
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
        /*
            Adicionando o usuario(logado) na lista de amigos do seu novo amigo
        */
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
        // atribuindo os valores do novo amigo ao usuario logado
        usuarioEspecifico->listaDeAmigos->perfilDoUsuario->id = usuAux->perfilDoUsuario->id;
        usuarioEspecifico->listaDeAmigos->perfilDoUsuario->idade = usuAux->perfilDoUsuario->idade;
        usuarioEspecifico->listaDeAmigos->perfilDoUsuario->nome = usuAux->perfilDoUsuario->nome;

        // atribuindo os valores do usuario logado ao novo amigo
        usuAux->listaDeAmigos->perfilDoUsuario->id = usuarioEspecifico->perfilDoUsuario->id;
        usuAux->listaDeAmigos->perfilDoUsuario->idade = usuarioEspecifico->perfilDoUsuario->idade;
        usuAux->listaDeAmigos->perfilDoUsuario->nome = usuarioEspecifico->perfilDoUsuario->nome;
        // removendo o convite da row de solicitacoes do usuario logado
        row = removeSolicitacao(row);
        usuarioEspecifico->amigosPendentes = row;
        return usuarioEspecifico->amigosPendentes;
    }
    else
        return NULL;
}

// aceita todos os convites
Fila *aceitaTodas(Fila *row, User *usuarioEspecifico, User *usuarios)
{
    while (row != NULL)
    {
        row = aceitaSolicitacao(row, usuarioEspecifico, usuarios);
    }
    return row;
}
// imprimi na tela todas as solicitacoes
void imprimirSolicitacao(Fila *row, User *usuarios)
{
    if (row == NULL)
        printf("\n\nFim da lista\n\n");
    else
    {
        Perfil *usuAux = NULL;
        usuAux = procuraUserId2(usuarios, row->id);
        if (usuAux == NULL)
            printf("\n\t O usuario %d nao foi encontrado", row->id);
        else
            imprimirPerfil(usuAux);
        return imprimirSolicitacao(row->proximo, usuarios);
    }
}