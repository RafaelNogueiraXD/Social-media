// funcoes da fila de requisições 
#include "perfil.c"

typedef struct filaRequisicoes{
 int id; 
 struct filaRequisicoes *proximo;
}Fila;

Fila *insereSolicitacao(Fila *pilha, int id){
    if (pilha == NULL){
        Fila *filaReq = (Fila *)malloc(sizeof(Fila));
        filaReq->id = id;
        filaReq->proximo = NULL;
        return filaReq;
    }else{
        Fila *filaReq = (Fila *)malloc(sizeof(Fila));
        filaReq->id = id;
        filaReq->proximo = pilha;
        return filaReq;
    }
}

Fila *removeSolicitacao(Fila *pilha){
    Fila *proximoAux = pilha->proximo;
    free(pilha);
    return proximoAux;
}
void imprimirSolicitacao(Fila* pilha,User*usuarios){
    if(pilha == NULL);
    else{
        Perfil *usuAux = NULL;
        usuAux = procuraUserId2(usuarios,pilha->id);
        if(usuAux == NULL)printf("\n\t o usuario %d nao esta mais presente.", pilha->id);
        else imprimirPerfil(usuAux);
        return imprimirSolicitacao(pilha->proximo, usuarios);
    }
}