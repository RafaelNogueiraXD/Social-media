#include "testes/factory.c"
int intercefaceGeral(User * usuario){
    int comando = 0;
        system("cls");
        printf("\n\n\t\t Interface do Programa! \n\n");
        printf("\n Opcoes Gerais: \n");
        printf("\n\t1 - cria novo Usuario");
        printf("\n\t2 - mostra Usuarios");
        printf("\n\t3 - procura Usuarios");
        printf("\n\t4 - remove Usuario");
        printf("\n\t99 - Injetar gama de usuarios");
        printf("\n\t5 - selecione o Usuario(Login)");
        if(usuario == NULL)printf("\n\tFaca o login para liberar as outras opcoes");
        else{
            printf("\n\n Opcoes para o usuario %s: \n", usuario->perfilDoUsuario->nome);
            printf("\n\t6 - ver solicitacaos ");
            printf("\n\t7 - enviar solicitacao ");
            printf("\n\t8 - recusar solicitacao ");
            printf("\n\t9 - sair da conta(Logout)");
        }
        printf("\nEscolha: ");
        scanf("%d",&comando);
        getchar();
        return comando; 
}
User *injetarUsuarios(){
    User* fakes = NULL;
    for (int i = 0; i < 10; i++)fakes = insereUserRand(fakes);
    return fakes;
}