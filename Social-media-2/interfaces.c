#include "testes/factory.c"
int intercefaceGeral(User * usuario, User *listaUsuarios){
    int comando = 0;
        //system("clear");
        printf("\n Opcoes Gerais: \t\t\tNº usuarios: %d \n", numUsuarios(listaUsuarios));
        printf("\n\t0 - Fechar programa");
        printf("\n\t1 - cria novo Usuario");
        printf("\n\t2 - mostra Usuarios");
        printf("\n\t3 - procura Usuarios");
        printf("\n\t4 - remove Usuario");
        printf("\n\t5 - selecione o Usuario(Login)");
        printf("\n\t99 - Injetar gama de usuarios");
        if(usuario == NULL)printf("\n\tFaca o login para liberar as outras opcoes");
        else{
            printf("\n\n Opcoes para o usuario %s: \n", usuario->perfilDoUsuario->nome);
            printf("\n\t6 - ver solicitacaos ");
            printf("\n\t7 - enviar solicitacao ");
            printf("\n\t8 - aceita solicitacao ");
            printf("\n\t9 - recusar solicitacao ");
            printf("\n\t100 - sair da conta(Logout)");
        }
        printf("\nEscolha: ");
        scanf("%d",&comando);
        if(usuario == NULL && comando>5 && comando!=99){
            printf("Digite uma opcao valida\n");
            return intercefaceGeral(usuario,listaUsuarios);
        }
        getchar();
        return comando; 
}

User *injetarUsuarios(User*usuario){
    for (int i = 0; i < 10; i++)usuario = insereUserRand(usuario);
    return usuario;
}