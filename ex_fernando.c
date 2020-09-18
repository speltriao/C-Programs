#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

int main()
{
    int tamanho;
    char valor;
    printf("Digite o tamanho");
    scanf("%d",&tamanho);
    fflush(stdin);
    Pilha P = pilha(tamanho);
    for (int i = 0; i < tamanho; i++)
    {
        printf("Digite o valor");
        scanf(" %c",&valor);
        if (vaziap(P)||(valor!=topo(P))) //Se a pilha estiver vazia, já empilha//
        {
            empilha(valor,P);
        }
        
        else 
        {
            desempilha(P);
        }

    }
    if (vaziap(P))
    {
        printf("É Concha");
    }
    else
    {
        printf("Não é concha");
    }
    
    return 0;
}