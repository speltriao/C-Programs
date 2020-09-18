#include<stdio.h>
#include<stdlib.h>
#include "pilha.h"

int maior(Pilha P)
{
    int tamanho = (P->topo)+1;
    int vetor[tamanho],aux;

    for (int i = 0; i < tamanho; i++)
    {
        vetor[i]=P->item[(P->topo-i)];
        
    }
    for (int i = 0; i < tamanho; i++) //vetor em ordem decrescente
    {
        for (int j = i+1; j < tamanho; j++)
        {
            if (vetor[i]<vetor[j])
            {
                aux=vetor[i];
                vetor[i]=vetor[j];
                vetor[j]=aux;
            }            
        }
    }
    printf("%d",vetor[0]);
    return(vetor[0]);//Primeiro item de uma sequencia decrescente certamente será o maior 

}
int main()
{
    Pilha P = pilha(10);
    empilha(1,P);
    empilha(20,P);
    empilha(2,P);
    empilha(3,P);
    maior(P);


    return 0;
}