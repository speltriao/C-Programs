#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "pilha.h"


int calcular_pos(char entrada[])
{
    int aux;
    int tamanho=strlen(entrada);
    Pilha P = pilha(tamanho);
    
    for (int i = 0; entrada[i]; i++)
    {
        if (isdigit(entrada[i]))
        {
            aux = entrada[i]-'0';
            empilha(aux,P);
        }
        else if (strchr("+",entrada[i]))
        {
            aux=desempilha(P);
            aux+=desempilha(P);
            empilha(aux,P);
        }
        else if (strchr("-",entrada[i]))
        {
            aux=desempilha(P);
            aux-=desempilha(P);
            empilha(aux,P);
        }
        else if (strchr("*",entrada[i]))
        {
            aux=desempilha(P);
            aux*=desempilha(P);
            empilha(aux,P);
        }
        else if (strchr("/",entrada[i]))
        {
            aux=desempilha(P);
            aux/=desempilha(P);
            empilha(aux,P);
        }

        
    }

    printf("%d",desempilha(P));
}

int main()
{
    calcular_pos("23*84/+");
    return 0;
}