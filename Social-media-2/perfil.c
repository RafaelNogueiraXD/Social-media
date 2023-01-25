// funcoes da struct Perfil
struct perfil
{
    int id; // identificação do usuário;
    char *nome;
    int idade;
    // adicionar outras informações relevantes
};

typedef struct perfil Perfil;
struct user
{
    Perfil *perfilDoUsuario;                 // informações do usuario
    struct user *listaDeAmigos;              // lista de amigos já confirmados
    struct filaRequisicoes *amigosPendentes; // fila de amigos ainda não confirmados
    struct user *proximo;                    // ponteiro para o próximo usuario da lista
};
typedef struct user User;

Perfil *addPerfil()
{
    Perfil *usuario = (Perfil *)malloc(sizeof(Perfil));
    usuario->nome = (char *)malloc(sizeof(char) * 150);
    usuario->id = NULL;
    printf("\n digite o nome do Usuario:");
    gets(usuario->nome);
    printf("\n digite a idade:");
    scanf("%d", &usuario->idade);
    getchar();
    return usuario;
}

User *insereUser(User *lista)
{
    int contId = 1;
    if (lista == NULL)
    {
        User *usuario = (User *)malloc(sizeof(User));
        usuario->perfilDoUsuario = addPerfil();
        usuario->perfilDoUsuario->id = 1;
        usuario->listaDeAmigos = NULL;
        usuario->amigosPendentes = NULL;
        usuario->proximo = NULL;
        return usuario;
    }
    else
    {
        User *listaAux = lista;
        while (listaAux->proximo != NULL)
        {
            contId++;
            listaAux = listaAux->proximo;
        }

        User *usuario = (User *)malloc(sizeof(User));
        usuario->perfilDoUsuario = addPerfil();
        usuario->perfilDoUsuario->id = contId + 1;
        usuario->listaDeAmigos = NULL;
        usuario->amigosPendentes = NULL;
        usuario->proximo = NULL;

        listaAux->proximo = usuario;
        return lista;
    }
}
void imprimirUsers(User *usuarios)
{
    static int tabela = 0;
    if (tabela == 0)
        printf("\n\n\tid\t|\tnome\t|\tidade\n");
    tabela++;
    if (usuarios == NULL)
        printf("\n\t!! Fim lista \n");
    else
    {
        imprimirPerfil(usuarios->perfilDoUsuario);
        printf("\n\t");
        for (int i = 0; i < 50; i++)
            printf("-");
        return imprimirUsers(usuarios->proximo);
    }
}
void imprimirPerfil(Perfil *usuarios)
{
    if (usuarios == NULL)
        return NULL;
    printf("\n\t%d\t", usuarios->id);
    printf("=\t%s\t", usuarios->nome);
    printf("\t%d \n", usuarios->idade);
}

User *procuraUserId(User *usuarios, int id)
{
    if (usuarios == NULL)
    {
        printf("\n Nenhum usuario encontrado! \n");
        return NULL;
    }
    if (usuarios->perfilDoUsuario->id == id)
    {
        printf("\nPerfil encontrado: \n");
        printf("\n\n\tid\t|\tidade\n");
        return usuarios;
    }
    else
        return procuraUserId(usuarios->proximo, id);
}

int numAmigos(User *AmigosUsuario)
{

    User *AmigoAux = AmigosUsuario;
    int contador = 0;

    if (AmigoAux == NULL)
        return NULL;

    while (AmigoAux != NULL)
    {
        contador++;
        AmigoAux = AmigoAux->proximo;
    }

    return contador;
}

int numUsuarios(User *usuarios)
{

    User *usuaux = usuarios;
    int contador = 0;

    if (usuaux == NULL)
        return NULL;

    while (usuaux != NULL)
    {
        contador++;
        usuaux = usuaux->proximo;
    }

    return contador;
}

Perfil *procuraUserId2(User *usuarios, int id)
{
    if (usuarios == NULL)
    {
        printf("\n Nenhum usuario encontrado! \n");
        return NULL;
    }
    if (usuarios->perfilDoUsuario->id == id)
    {
        return usuarios->perfilDoUsuario;
    }
    else
        return procuraUserId2(usuarios->proximo, id);
}

Perfil *printaAmigos(User *usuarios) {}

Perfil *procuraUserNome(User *usuarios, char nome[150])
{
    if (usuarios == NULL)
    {
        printf("\n Nenhum usuario encontrado! \n");
        return NULL;
    }
    if (strcmp(usuarios->perfilDoUsuario->nome, nome) == 0)
    {
        printf("\nPerfil encontrado: \n");
        printf("\n\n\tid\t|\tnome\t|\tidade\n");
        return usuarios->perfilDoUsuario;
    }
    else
        return procuraUserNome(usuarios->proximo, nome);
}

User *removeUserId(User *usuarios, int id)
{
    if (usuarios == NULL)
    {
        return usuarios;
    }
    else
    {
        User *inicio = usuarios;
        User *anterior = NULL;
        while (usuarios != NULL)
        {
            if (usuarios->perfilDoUsuario->id == id)
            {
                printf("\n \t!! Removendo o usuario : %s !! \n", usuarios->perfilDoUsuario->nome);
                if (anterior == NULL)
                {
                    User *proximoAux = usuarios->proximo;
                    free(usuarios->perfilDoUsuario->nome);
                    free(usuarios->perfilDoUsuario);
                    free(usuarios);
                    return proximoAux;
                }
                else
                {
                    anterior->proximo = usuarios->proximo;
                    free(usuarios->perfilDoUsuario->nome);
                    free(usuarios->perfilDoUsuario);
                    free(usuarios);
                    return inicio;
                }
            }
            anterior = usuarios;
            usuarios = usuarios->proximo;
        }
    }
}

User *removeUserNome(User *usuarios, char nome[150])
{
    if (usuarios == NULL)
    {
        return usuarios;
    }
    else
    {
        User *inicio = usuarios;
        User *anterior = NULL;
        while (usuarios != NULL)
        {
            if (strcmp(usuarios->perfilDoUsuario->nome, nome) == 0)
            {
                printf("\n \t!! Removendo o usuario : %s !! \n", usuarios->perfilDoUsuario->nome);
                if (anterior == NULL)
                {
                    User *proximoAux = usuarios->proximo;
                    free(usuarios->perfilDoUsuario->nome);
                    free(usuarios->perfilDoUsuario);
                    free(usuarios);
                    return proximoAux;
                }
                else
                {
                    anterior->proximo = usuarios->proximo;
                    free(usuarios->perfilDoUsuario->nome);
                    free(usuarios->perfilDoUsuario);
                    free(usuarios);
                    return inicio;
                }
            }
            anterior = usuarios;
            usuarios = usuarios->proximo;
        }
    }
}

User *quemEhOPerfilMaisAmigo(User *listaUser)
{

    int maior = 0, atual = 0;

    User *listaUserAux = listaUser;
    User *userAtual = NULL;

    while (listaUserAux != NULL)
    {
        atual = numAmigos(listaUserAux->listaDeAmigos);
        if (atual > maior)
        {
            maior = atual;
            userAtual = listaUserAux;
        }
        listaUserAux = listaUserAux->proximo;
    }
    return userAtual;
}
