#include <stdio.h>
#include <string.h>
#include "pilha.h"


char* valor(char entrada[])
{
   
    int tamanho=strlen(entrada);
    int contador_sinais=0;
    char sinais[tamanho];
    char resposta;
    Pilha P = pilha(tamanho);
    if (strchr(entrada,'V')||(strchr(entrada,'F')))
    {
        contador_sinais+=1;
    }
    else
    {
        contador_sinais+=1;
    }
    printf("%d",contador_sinais);
    
}


int main()
{
    
    printf("%c\n",valor("VFV~&|"));

    return 0;
}