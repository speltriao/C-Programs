#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#define limite 1000
#define true 1
#define false 0

static int count = 0; //Global variable counting musics found

char* get_current_dir(){ //pega o diretório atual
    static char cwd[limite];
    getcwd(cwd, sizeof(cwd));
    return cwd;
}

char is_music(char* string){
 
    if((strstr(string, ".mp3"))||(strstr(string, ".m4a"))||(strstr(string,".wav"))) return true;
    else return false;
}

void list_files(char* diretorio){
    
    char novo_dir[limite];
    struct dirent *dir;
    DIR *d = opendir(diretorio);
    if (!d) return; //Diretorio invalido

    while (dir = readdir(d)){ //Enquanto existir diretorio
        if ((strcmp(dir->d_name, "."))&&(strcmp(dir->d_name, ".."))){ //Desconsiderar os ".."(parent directory)"."(current directory)(unix)
		    
            if(is_music(dir->d_name)==true) count++;
            
            strcpy(novo_dir,diretorio);//strcat(destination, source)
            strcat(novo_dir,"/"); //coloca a barra no final do novo caminho
            strcat(novo_dir,dir->d_name); /*coloca cada diretorio (e arquivo, aqui ele n sabe o q é o q) apos a barra do novo caminho.
            Ai ele vai tentando acessar o novo diretorio. Se for um arquivo, o diretorio será inválido.
            Se for um diretorio, ele vai tentando entrar em cada arquivo e ou diretorio, sucessivamente*/ 
            list_files(novo_dir);//Recursão com o novo diretório
        }
    }
    closedir(d);
    
}

int main(void)
{
    char entrada;
    list_files(get_current_dir());
    printf("Quantidade de musicas: %d\n",count);
    printf("Pressione Enter para continuar");
    scanf("%c",&entrada);
    if (entrada==10) exit(0);
    return 0;
}
