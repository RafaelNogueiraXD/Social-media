#include <stdio.h>
#include <stdlib.h>
#include "filaRequisicoes.c"
int main(){
    int op =2 ;
    User* usuario  = NULL;
    User* usuarioEspecifico  = NULL;
    usuario = insereUser(usuario);
    usuario = insereUser(usuario);
    imprimirUsers(usuario);
    // printf("\nDigite o nome do usuario que deseja ver: ");
    // gets(op);
    // imprimirPerfil(procuraUserNome(usuario,op));
    // usuario = removeUserNome(usuario, op);
    usuarioEspecifico = procuraUserId(usuario,op);
    imprimirUsers(usuarioEspecifico);
    Fila *filateste = NULL;
    filateste = insereSolicitacao(filateste, 1);
    filateste = insereSolicitacao(filateste, 2);
    filateste = insereSolicitacao(filateste, 3);
    usuarioEspecifico->listaDeAmigos = filateste;
    printf("\n \n mostra lista de Solicitacoes:");
    printf("\n\n\tid\t|\tidade\n");
    imprimirSolicitacao(usuarioEspecifico->listaDeAmigos, usuario);
   
   
    // filateste = removeSolicitacao(filateste);
   
    // printf("\n \n mostra lista:");
    // imprimirSolicitacao(filateste);
    

}