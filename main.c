#include <stdio.h>
#include <stdlib.h>
#include "filaRequisicoes.c"
#include "interfaces.c"
int main(){
    int op, comando;
    User* usuario  = NULL;
    User* usuarioEspecifico  = NULL;
    
    do{
        comando = intercefaceGeral(usuarioEspecifico);
        switch (comando){
            case 1: // cria novo user
                usuario = insereUser(usuario);
                break;
            case 2:// imprimi os iusuarios
                imprimirUsers(usuario);
                break;
            case 3://procura por usuario especifico
                imprimirUsers(usuario);
                printf("\n Digite o id do usuario: ");
                scanf("%d", &op);
                imprimirPerfil(procuraUserId2(usuario,op));
                break;
            case 4://remove usuario
                imprimirUsers(usuario);
                printf("\n Digite o id do usuario que deseja remover: ");
                scanf("%d", &op);
                if(usuarioEspecifico->perfilDoUsuario->id == op)usuarioEspecifico = NULL;
                usuario = removeUserId(usuario, op);
                break;
            case 5://seleciona usuario
                imprimirUsers(usuario);
                printf("\n Digite o id do usuario: ");
                scanf("%d", &op);
                usuarioEspecifico = procuraUserId(usuario,op);
                imprimirUsers(usuarioEspecifico);
                break;
            case 6: // ver convites recebidos
                printf("\n ver convites ... ");
                imprimirSolicitacao(usuarioEspecifico->amigosPendentes,usuario);
                break;
            case 7: // envia convites
                printf("\n enviando convite ... ");
                User* futuroAmigo = NULL;
                printf("\n Digite o id do usuario: ");
                scanf("%d", &op);
                futuroAmigo = procuraUserId(usuario,op);
                imprimirPerfil(futuroAmigo->perfilDoUsuario);
                futuroAmigo->amigosPendentes = enviaSolicitacao(futuroAmigo->amigosPendentes, usuarioEspecifico->perfilDoUsuario->id);
                break;
            case 8: // aceita convites
                printf("\n aceitando convite ... ");
                break;
            case 9: // recusa convites
                printf("\n recusando convite ... ");
                usuarioEspecifico->amigosPendentes = removeSolicitacao(usuarioEspecifico->amigosPendentes);
                break;
            case 100:
                usuarioEspecifico = NULL;
                break;
            case 99:
                usuario = injetarUsuarios(usuario);
                break;
            
            default:
                comando != 0 ? printf("\n opcao invalida \n") : printf("\n encerrando programa \n");
                break;
        }
        printf("\n\n\tClique qualquer botao para continuar!");
        getch();
    } while (comando != 0);
    // usuario = insereUser(usuario);
    // printf("\nDigite o nome do usuario que deseja ver: ");
    // gets(op);
    // imprimirPerfil(procuraUserNome(usuario,op));

    // Fila *filateste = NULL;
    // filateste = insereSolicitacao(filateste, 1);
    // filateste = insereSolicitacao(filateste, 2);
    // filateste = insereSolicitacao(filateste, 3);
    // usuarioEspecifico->listaDeAmigos = filateste;
    // printf("\n \n mostra lista de Solicitacoes:");
    // printf("\n\n\tid\t|\tidade\n");
    // imprimirSolicitacao(usuarioEspecifico->listaDeAmigos, usuario);
   
   
    // filateste = removeSolicitacao(filateste);
   
    // printf("\n \n mostra lista:");
    // imprimirSolicitacao(filateste);
    

}