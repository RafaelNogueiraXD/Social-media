// funcoes da struct Perfil 
struct perfil{
    int id; //identificação do usuário;
    char *nome;
    int idade;
    //adicionar outras informações relevantes
};

typedef struct perfil Perfil;
struct user{
 Perfil *perfilDoUsuario; //informações do usuario
 Perfil *listaDeAmigos; //lista de amigos já confirmados
 struct filaRequisicoes *amigosPendentes; //fila de amigos ainda não confirmados
 struct user *proximo; //ponteiro para o próximo usuario da lista
};
typedef struct user User;

Perfil* addPerfil(){
    Perfil *usuario = (Perfil*) malloc (sizeof(Perfil));
    usuario->nome = (char*) malloc (sizeof(char)*150);
    usuario->id = NULL; 
    printf("\n digite o nome do Usuario:");
    gets(usuario->nome);
    printf("\n digite a idade:");
    scanf("%d",& usuario->idade);
    getchar();
    return usuario;
}

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
        usuario->perfilDoUsuario->id = contId + 1;
        usuario->listaDeAmigos = NULL; 
        usuario->amigosPendentes = NULL; 
        usuario->proximo = NULL;

        listaAux->proximo = usuario;  
        return lista;
    } 
}
void imprimirUsers(User* usuarios){
    static int tabela = 0;
    if(tabela == 0)printf("\n\n\tid\t|\tnome\t|\tidade\n");
    tabela++;
    if(usuarios == NULL)printf("\n\t!! Fim lista \n");
    else{
        imprimirPerfil(usuarios->perfilDoUsuario);
        printf("\n\t");
        for(int i= 0; i< 50; i++)printf("-");
        return imprimirUsers(usuarios->proximo);
    }
}
void imprimirPerfil(Perfil* usuarios){
    printf("\n\t%d\t", usuarios->id);
    printf("=\t%s\t", usuarios->nome);
    printf("\t%d \n", usuarios->idade);
}

Perfil *procuraUserId(User* usuarios, int id){
    if(usuarios == NULL)printf("\n Nenhum usuario encontrado! \n");
    if(usuarios->perfilDoUsuario->id == id){
        printf("\nPerfil encontrado: \n");
        printf("\n\n\tid\t|\tidade\n");
        return usuarios->perfilDoUsuario;}
    else return procuraUserId(usuarios->proximo, id);
}
Perfil *procuraUserNome(User* usuarios, char nome[150]){
    if(usuarios == NULL)printf("\n Nenhum usuario encontrado! \n");
    if(strcmp(usuarios->perfilDoUsuario->nome ,nome)== 0){
        printf("\nPerfil encontrado: \n");
        printf("\n\n\tid\t|\tnome\t|\tidade\n");
        return usuarios->perfilDoUsuario;}
    else return procuraUserNome(usuarios->proximo, nome);
}