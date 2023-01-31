#include "testes/factory.c"
int intercefaceGeral(User * usuario, User *listaUsuarios){
    int comando = 0;
        //system("clear");
        //mostra todas as opcoes para o usuario
        printf("\n Opcoes Gerais: \t\t\tUsuarios Registrados: %d \n", numUsuarios(listaUsuarios));
        printf("\n\t0 - Fechar programa");
        printf("\n\t1 - cria novo Usuario");
        printf("\n\t2 - mostra Usuarios");
        printf("\n\t3 - procura Usuarios");
        printf("\n\t4 - remove Usuario");
        printf("\n\t5 - selecione o Usuario(Login)");
        printf("\n\t13 - numero de usuarios");
        printf("\n\t15 - Usuario com mais amigos");
        printf("\n\t99 - Injetar gama de usuarios");
        if(usuario == NULL)printf("\n\tFaca o login para liberar as outras opcoes");
        else{ //opcoes apenas para quando o usuario esta logado
            printf("\n\n Opcoes para o usuario %s: \n", usuario->perfilDoUsuario->nome);
            printf("\n\t6 - ver solicitacaos ");
            printf("\n\t7 - enviar solicitacao ");
            printf("\n\t8 - aceita solicitacao ");
            printf("\n\t9 - recusar solicitacao ");
            printf("\n\t10 - aceitar todas solicitacoes ");
            printf("\n\t11 - rejeitar todas solicitacoes ");
            printf("\n\t12 - ver quantidade de amigos");
            printf("\n\t14 - numero de solicitacoes");
            printf("\n\t100 - sair da conta(Logout)");
        }
        printf("\nEscolha: ");
        scanf("%d",&comando);
        getchar();
        //se nao tem usuario no sistema e o usuario tentar acessar uma 
        //opcao acima de 5(salvo 3 exceções) ele será barrado
        if(usuario == NULL && comando>5 && comando!=99 && comando!=13 && comando!=15){
            printf("Digite uma opcao valida\n");
            return intercefaceGeral(usuario,listaUsuarios);
        }
        return comando; 
}
//func responsavel por injetar 10 usuarios aleatorios
User *injetarUsuarios(User*usuario){
    for (int i = 0; i < 10; i++)usuario = insereUserRand(usuario);
    return usuario;
}