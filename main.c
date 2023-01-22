#include <stdio.h>
#include <stdlib.h>
// #include "perfil.c"
#include "filaRequisicoes.c"
int main(){
    char op[150];
    User* usuario  = NULL;
    usuario = insereUser(usuario);
    usuario = insereUser(usuario);
    // usuario = insereUser(usuario);
    imprimirUsers(usuario);
    printf("\nDigite o nome do usuario que deseja ver: ");
    gets(op);
    imprimirPerfil(procuraUserNome(usuario,op));
}