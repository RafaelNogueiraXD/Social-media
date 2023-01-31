#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "filaRequisicoes.c"
#include "interfaces.c"
int main()
{
    //inicializa as variaveis e as Structs
    int op, comando;
    User *usuario = NULL; // lista geral de todos os usuarios
    User *usuarioEspecifico = NULL; // lista para logar com um usuario em especifico
    do
    {
        //imprimi menu e retorna a condicao do switch
        comando = intercefaceGeral(usuarioEspecifico, usuario);
        switch (comando)
        {
        case 1: // cria novo user
            usuario = insereUser(usuario);
            break;
        case 2: // imprimi os iusuarios
            imprimirUsers(usuario);
            break;
        case 3: // procura por usuario especifico
            imprimirUsers(usuario);
            printf("\n Deseja procurar por:\n\t 1 - nome\n\t 2 - ID\nEscolha: ");
            scanf("%d", &op);
            getchar();
            if (op == 1) // opcao para procurar por nome
            {
                char nome[150];
                printf("\n Digite o nome do usuario: ");
                gets(nome);
                imprimirPerfil(procuraUserNome(usuario, nome));
            }
            else if (op == 2) // opcao para procurar por ID
            {
                printf("\n Digite o id do usuario: ");
                scanf("%d", &op);
                getchar();
                imprimirPerfil(procuraUserId2(usuario, op));
            }
            else
            {
                printf("\n opcao invalida \n");
            }
            break;
        case 4: // remove usuario
            imprimirUsers(usuario);
            printf("\n Deseja apagar por:\n\t1 - Nome\n\t2 - ID\nEscolha: ");
            scanf("%d", &op);
            getchar();
            if (op == 1)// opcao para procurar por nome
            {
                char nome[150];
                printf("\n Digite o nome do usuario: ");
                gets(nome);
                if (usuarioEspecifico != NULL)
                    if (strcmp(usuarioEspecifico->perfilDoUsuario->nome, nome) == 0)
                        usuarioEspecifico = NULL;
                usuario = removeUserNome(usuario, nome);
            }
            else if (op == 2)// opcao para procurar por ID
            {
                printf("\n Digite o id do usuario que deseja remover: ");
                scanf("%d", &op);
                if (usuarioEspecifico != NULL)
                    if (usuarioEspecifico->perfilDoUsuario->id == op)
                        usuarioEspecifico = NULL;
                usuario = removeUserId(usuario, op);
            }
            else
            {
                printf("\n opcao invalida \n");
            }
            break;
        case 5: // seleciona usuario por ID
            imprimirUsers(usuario);
            printf("\n Digite o id do usuario: ");
            scanf("%d", &op);
            usuarioEspecifico = procuraUserId(usuario, op);
            imprimirUsers(usuarioEspecifico);
            break;
        case 6: // ver convites recebidos
            printf("\n ver convites ... ");
            imprimirSolicitacao(usuarioEspecifico->amigosPendentes, usuario);
            break;
        case 7: // envia convites
            printf("\n enviando convite ... ");
            User *futuroAmigo = NULL;
            do
            {
                printf("\n Digite o id de outro usuario: ");
                scanf("%d", &op);
            } while (usuarioEspecifico->perfilDoUsuario->id == op);

            //procura usuario digitado
            futuroAmigo = procuraUserId(usuario, op);

            if (futuroAmigo != NULL)//se futuroAmigo for diferente de nulo a solitacao nao enviada
            {
                if (verificaFila(op, usuarioEspecifico->amigosPendentes) == 1)
                {
                    printf("\n\n\n\nErro! Voce ja possui uma solicitacao desse usuario\n\n\n\n");
                    break;
                }
                if (verificaFila(usuarioEspecifico->perfilDoUsuario->id, futuroAmigo->amigosPendentes) == 1)
                {
                    printf("\n\n\n\nErro! Voce ja enviou uma solicitacao para esse usuario\n\n\n\n");
                    break;
                }

                // imprimirPerfil(futuroAmigo->perfilDoUsuario);
                futuroAmigo->amigosPendentes = enviaSolicitacao(futuroAmigo->amigosPendentes, usuarioEspecifico->perfilDoUsuario->id);
            }
            break;
        case 8: // aceita convites
            printf("\n aceitando convite ... ");
            usuarioEspecifico->amigosPendentes = aceitaSolicitacao(usuarioEspecifico->amigosPendentes, usuarioEspecifico, usuario);
            break;
        case 9: // recusa convites
            printf("\n recusando convite ... ");
            usuarioEspecifico->amigosPendentes = removeSolicitacao(usuarioEspecifico->amigosPendentes);
            break;
        case 10://aceita todos os convites
            usuarioEspecifico->amigosPendentes = aceitaTodas(usuarioEspecifico->amigosPendentes, usuarioEspecifico, usuario);
            break;
        case 11: // recusa todos os convites
            usuarioEspecifico->amigosPendentes = rejeitaTodos(usuarioEspecifico->amigosPendentes, usuarioEspecifico, usuario);
            break;
        case 12: //verifica o numero de amigos 
            printf("\n\n\n\nnumero de Amigos: %d\n\n\n\n", numAmigos(usuarioEspecifico->listaDeAmigos));
            break;
        case 13: // verifica numero de usuarios no sistema
            printf("\n\n\n\nnumero de Usuarios: %d\n\n\n\n", numUsuarios(usuario));
            break;
        case 14: // verifica numero de solicitacoes do usuario
            printf("\n\n\n\nnumero de solicitacoes: %d\n\n\n\n", numSolicitacoes(usuarioEspecifico->amigosPendentes));
            break;
        case 15:// verifica numero de solicitacoes do usuario
        if(quemEhOPerfilMaisAmigo(usuario)!=NULL)
            imprimirPerfil(quemEhOPerfilMaisAmigo(usuario)->perfilDoUsuario);
        case 100:// faz logout da conta de um usuario
            usuarioEspecifico = NULL;
            break;
        case 99: // injeta 10 usuarios no sistema
            usuario = injetarUsuarios(usuario);
            break;
        default:
            comando != 0 ? printf("\n opcao invalida \n") : printf("\n encerrando programa \n");
            break;
        }
        // printf("\n\n\tClique qualquer botao para continuar!");
        //  getch();
    } while (comando != 0);
}