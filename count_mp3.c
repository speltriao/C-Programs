#include <stdio.h>
#include <string.h>
#include <dirent.h>

int count_music(char* string, int* count){
	if(strstr(string, ".mp3")) {
		*count +=1;
	}
	return *count;
}

int main(void)
{
	int count = 0;
    DIR *d;
    struct dirent *dir;
    d = opendir(".");
    while ((dir = readdir(d)))
    {
    	//printf("%s\n", dir->d_name);
		count_music(dir->d_name,&count);
    }
    closedir(d);
	printf("\nQntd de MP3: %d\n",count);
    return 0;
}
