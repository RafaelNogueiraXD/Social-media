//código feito por Thiago Bortoluzzi e Rafael Nogueira

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
// aloca e preenche uma struct perfil
Perfil *addPerfil() // Funçao feita por Rafael
{
    Perfil *usuario = (Perfil *)malloc(sizeof(Perfil));
    usuario->nome = (char *)malloc(sizeof(char) * 150);
    usuario->id = usuario->id;
    // entrada de dados
    printf("\n digite o nome do Usuario:");
    gets(usuario->nome);
    printf("\n digite a idade:");
    scanf("%d", &usuario->idade);
    getchar();
    return usuario;
}
// aloca e preenche uma struct User
User *insereUser(User *lista) // Funçao feita por Rafael
{
    int contId = 1;
    if (lista == NULL) // se for o 1 usuario do sistema
    {
        User *usuario = (User *)malloc(sizeof(User));
        usuario->perfilDoUsuario = addPerfil();
        usuario->perfilDoUsuario->id = 1;
        usuario->listaDeAmigos = NULL;
        usuario->amigosPendentes = NULL;
        usuario->proximo = NULL;
        return usuario;
    }
    else // se for o N usuario do sistema
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
// imprime perfil
void imprimirPerfil(Perfil *usuarios) // Funçao feita por Rafael
{
    if (usuarios == NULL)
        return;
    printf("\n\t%d\t", usuarios->id);
    printf("=\t%s\t", usuarios->nome);
    printf("\t%d \n", usuarios->idade);
}

// imprime usuarios
void imprimirUsers(User *usuarios) // Funçao feita por Rafael
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

// imprime amigos
void imprimirAmigos(User *UsuarioEspecifico) // Funçao feita por Rafael
{
    User *UserAux = UsuarioEspecifico->listaDeAmigos;
    if (UserAux == NULL)
        printf("\n\tO usuario nao possui amigos.");

    printf("\n\tOs amigos de %s sao: ", UsuarioEspecifico->perfilDoUsuario->nome);

    while (UserAux != NULL)
    {
        // imprimirPerfil(UserAux->perfilDoUsuario);
        if (UserAux->proximo == NULL)
            printf("%s.\n\n", UserAux->perfilDoUsuario->nome);
        else
            printf("%s , ", UserAux->perfilDoUsuario->nome);
        UserAux = UserAux->proximo;
    }
}

// procura usuario por ID (funcao recursiva) retorna User
User *procuraUserId(User *usuarios, int id) // Funçao feita por Rafael
{
    if (usuarios == NULL)
    {
        printf("\n Nenhum usuario encontrado! \n");
        return NULL;
    }
    if (usuarios->perfilDoUsuario->id == id)
    {
        // printf("\nPerfil encontrado: \n");
        // printf("\n\n\tid\t|\tidade\n");
        return usuarios;
    }
    else
        return procuraUserId(usuarios->proximo, id);
}

// retorna o numero total amigos de um determinado usuario
int numAmigos(User *AmigosUsuario) // Funçao feita por Thiago
{

    User *AmigoAux = AmigosUsuario;
    int contador = 0;

    if (AmigoAux == NULL)
        return 0;

    while (AmigoAux != NULL)
    {
        contador++;
        AmigoAux = AmigoAux->proximo;
    }

    return contador;
}
// retorna o numero total usuarios do sistema
int numUsuarios(User *usuarios) // Funçao feita por Thiago
{

    User *usuaux = usuarios;
    int contador = 0;

    if (usuaux == NULL)
        return 0;

    while (usuaux != NULL)
    {
        contador++;
        usuaux = usuaux->proximo;
    }

    return contador;
}
// retorna o perfil de um usuario com base no ID
Perfil *procuraUserId2(User *usuarios, int id) // Funçao feita por Rafael
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

// procura usuario por Nome e retorna perfil
Perfil *procuraUserNome(User *usuarios, char nome[150]) // Funçao feita por Rafael
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
//procura o usuario por nome e retorna a struct
User *procuraUserNome2(User *usuarios, char nome[150]) // Funçao feita por Rafael
{
    User *userAux = usuarios;
    if (userAux == NULL)
    {
        return NULL;
    }
    if (strcmp(userAux->perfilDoUsuario->nome, nome) == 0)
    {
        return userAux;
    }
    else
        return procuraUserNome2(userAux->proximo, nome);
}

// remove usuario pelo ID
int removeUserId(User *usuarios, int id) // Funçao feita por Rafael
{
    int removido = 0;
    if (usuarios == NULL)
    {
        return 0;
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
                    removido = 1;
                }
                else
                {
                    anterior->proximo = usuarios->proximo;
                    free(usuarios->perfilDoUsuario->nome);
                    free(usuarios->perfilDoUsuario);
                    free(usuarios);
                    removido = 1;
                }
            }
            anterior = usuarios;
            usuarios = usuarios->proximo;
        }
    }
    if (removido == 1)
        return removido;
    else
        return 0;
}
//remove usuario por nome e retorna 0(nao foi removido) ou 1(foi removido)
int removeUserNome(User *usuarios, char nome[150]) // Funçao feita por Rafael
{
    int removido = 0;
    if (usuarios == NULL)
    {
        return 0;
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
                    removido = 1;
                    // return proximoAux;
                }
                else
                {
                    anterior->proximo = usuarios->proximo;
                    free(usuarios->perfilDoUsuario->nome);
                    free(usuarios->perfilDoUsuario);
                    free(usuarios);
                    removido = 1;
                    // return inicio;
                }
            }
            anterior = usuarios;
            usuarios = usuarios->proximo;
        }
    }
    if (removido == 1)
        return removido;
    else
        return 0;
}
//verifica o perfil com mais mais amigos e retorna a STRUCT
User *quemEhOPerfilMaisAmigo(User *listaUser) // Funçao feita por Thiago
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

int verificaListaAmigos(User *amigosDoUsuario, int idEspecifico) // Funçao feita por Thiago
{

    User *amigosAux = amigosDoUsuario;

    while (amigosAux != NULL)
    {
        if (amigosAux->perfilDoUsuario->id == idEspecifico)
            return 1;
        else
            amigosAux = amigosAux->proximo;
    }

    return 0;
}
/*
Função para realizar o “match” entre perfis. 
*/

int numAmigosEmComum(User *user1, User *user2) // Funçao feita por Rafael
{

    int contador = 0;
    User *usuarioUm = user1->listaDeAmigos;
    User *usuarioDois = user2->listaDeAmigos;

    if (usuarioUm == NULL || usuarioDois == NULL)
        return 0;

    while (usuarioUm != NULL)
    {
        if (procuraUserId(usuarioDois, usuarioUm->perfilDoUsuario->id) != NULL)
            contador++;
        usuarioUm = usuarioUm->proximo;
    }
    usuarioDois = usuarioDois->proximo;

    return contador;
}

User *indicaAmigo(User *usuarioEspecifico, User *lista) // Funçao feita por Thiago
{
    int maior = 0, atual = 0;
    User *guardaUser;
    User *userAux = usuarioEspecifico;
    User *listaAux = lista;

    if (usuarioEspecifico == NULL || listaAux->listaDeAmigos == NULL){
        printf("\n\n\tNenhum sugestao de amizade disponivel para voce.\n\n");
        return NULL;
    }

    while (listaAux != NULL)
    {
        if (userAux->perfilDoUsuario->id != listaAux->perfilDoUsuario->id && verificaListaAmigos(listaAux->listaDeAmigos, userAux->perfilDoUsuario->id) == 0)
        { // condições para nao dar match com ele mesmo ou com alguem que ja é amigo

            atual = numAmigosEmComum(userAux, listaAux); // encontra o numero de amigos em comum do user em questao e dos users da lista e compara
            if (atual > maior)
            {
                maior = atual;
                guardaUser = listaAux;
            }
        }
        listaAux = listaAux->proximo;
    }

    if (maior == 0)
    {
        printf("\n\n\tNenhuma sugestao de amizade disponivel para voce.\n\n");
        return NULL;
    }
    else
    {
        printf("\n\n\nSugestao de amizade: %s (id: %d) - Voces tem %d amigo(s) em comum \n\n\n", guardaUser->perfilDoUsuario->nome,guardaUser->perfilDoUsuario->id, maior);
        return guardaUser;
    }
}
