// funcoes da fila de requisições 
#include "perfil.c"

typedef struct filaRequisicoes{
 int id; //identificação do
 Perfil *perfilUser;
 struct filaRequisicoes *proximo;
}Fila;

// Fila *InsereInicio(Fila *pilha, int valor)
// {

//     if (pilha == NULL)
//     {
//         Fila *filaReq = (Fila *)malloc(sizeof(Fila));
//         (*filaReq).perfilUser->id = 100;
//         (*filaReq).perfilUser->valor = 100;
//         (*filaReq).proximo = NULL;

//         return filaReq;
//     }
//     else
//     {
//         Fila *filaReq = (Fila *)malloc(sizeof(Fila));
//         (*filaReq).perfilUser = valor;
//         (*filaReq).proximo = pilha;

//         return filaReq;
//     }
// }

// Fila *RemoveInicio(Fila *pilha)
// {
//     Fila *proximoAux = pilha->proximo;
//     free(pilha);
//     return proximoAux;
// }
// void imprimir(Fila* pilha){
//     if(pilha == NULL)printf(" Fim lista \n");
//     else{
//         printf("\nid: %d ", pilha->perfilUser->id);
//         printf("\nidade %d ", pilha->perfilUser->idade);
//         return imprimir(pilha->proximo);
//     }
// }