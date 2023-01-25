Perfil *randomPerfil()
{
    Perfil *usuario = (Perfil *)malloc(sizeof(Perfil));
    usuario->nome = (char *)malloc(sizeof(char) * 150);
    usuario->id = NULL;
    char numChar[5], name[20] = "endrew";
    sprintf(numChar, "%d", rand() % 100);
    strncat(name, numChar, 5);
    strcpy(usuario->nome, name);
    usuario->idade = rand() % 100;
    return usuario;
}

User *insereUserRand(User *lista)
{
    int contId = 1;
    if (lista == NULL)
    {
        User *usuario = (User *)malloc(sizeof(User));
        usuario->perfilDoUsuario = randomPerfil();
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
        usuario->perfilDoUsuario = randomPerfil();
        usuario->perfilDoUsuario->id = contId + 1;
        usuario->listaDeAmigos = NULL;
        usuario->amigosPendentes = NULL;
        usuario->proximo = NULL;
        listaAux->proximo = usuario;
        return lista;
    }
}