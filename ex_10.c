#include <stdio.h>
#include "pilha.h"
#include "fila.h"

Fila ordenar(Fila F)
{
    int aux, contador=0, tamanho=F->max,vetor[tamanho];
    Pilha P = pilha(tamanho);
    while (!vaziaf(F))//Passa a fila F para um vetor
    {
        vetor[contador]=desenfileira(F);
        contador++;
    }
    
    for (int i = 0; i < contador; i++) //vetor crescente
    {
        for (int j = i+1; j < contador; j++)
        {
            if (vetor[i]>vetor[j])
            {
                aux=vetor[i];
                vetor[i]=vetor[j];
                vetor[j]=aux;
            }            
        }
    }
    for (int i = 0; i < contador; i++)//remove repetição
    {
        if (vetor[i]!=vetor[i+1])
        {
            empilha(vetor[i],P);
        }
        
    }
    while (!vaziap(P))//Recria a Fila F, invertendo o vetor crescente. Resulta numa Fila decrescente
    {
        enfileira(desempilha(P),F);
    }
    
    return(F);
}


int main() 
{
    Fila F = fila(10);
    int x[7] = {4, 2, 5, 1, 3, 2, 5}; 
    for(int i=0; i<7; i++) 
    {
        enfileira(x[i],F);
    }
    ordenar(F); 
    while( !vaziaf(F) ) printf("%d ", desenfileira(F));
    destroif(&F); 
    return 0; 

}
