#include <stdio.h>
#include <stdlib.h>
// #include "perfil.c"

#include "filaRequisicoes.c"


 //lista de usuários
struct user{
 Perfil *perfilDoUsuario; //informações do usuario
 Perfil *listaDeAmigos; //lista de amigos já confirmados
 struct filaRequisicoes *amigosPendentes; //fila de amigos ainda não confirmados
 struct user *proximo; //ponteiro para o próximo usuario da lista
};
typedef struct user User;
User* insereUser(User *lista){
    int contId =1;
    if(lista == NULL){
        User *usuario = (User*) malloc (sizeof(User));
        usuario->perfilDoUsuario = addPerfil(); 
        usuario->perfilDoUsuario->id = 1;
        usuario->listaDeAmigos = NULL; 
        usuario->amigosPendentes = NULL; 
        usuario->proximo = NULL;
        return usuario;
    }else{
        User *listaAux = lista;    
        while(listaAux->proximo != NULL){
            contId++;
            listaAux = listaAux->proximo;
        }

        User *usuario = (User*) malloc(sizeof(User));
        usuario->perfilDoUsuario = addPerfil(); 
        printf("%d",  contId + 1);
        usuario->perfilDoUsuario->id = contId + 1;
        usuario->listaDeAmigos = NULL; 
        usuario->amigosPendentes = NULL; 
        usuario->proximo = NULL;

        listaAux->proximo = usuario;  
        return lista;
    } 
}
void imprimir(User* usuario){
    if(usuario == NULL)printf("\n\t!! Fim lista \n");
    else{
        printf("\nid: %d ", usuario->perfilDoUsuario->id);
        printf("\nidade %d ", usuario->perfilDoUsuario->idade);
        return imprimir(usuario->proximo);
    }
}
int main(){
    User* usuario  = NULL;
    usuario = insereUser(usuario);
    usuario = insereUser(usuario);
    usuario = insereUser(usuario);
    imprimir(usuario);
    // printf("\nid : %d, idade: %d\n", usuario->perfilDoUsuario->id,usuario->perfilDoUsuario->idade);
    // printf("\n idade: %d \n",usu->idade);
}