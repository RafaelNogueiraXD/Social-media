// funcoes da struct Perfil 
struct perfil{
    int id; //identificação do usuário;
    //  char* nome;
    int idade;
    //adicionar outras informações relevantes
};
typedef struct perfil Perfil;
Perfil* addPerfil(){
    Perfil *usuario = (Perfil*) malloc (sizeof(Perfil));
    usuario->id = NULL; 
    scanf("%d",& usuario->idade);
    return usuario;
}
