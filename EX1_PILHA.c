#include<stdio.h>
#include "pilha.h"

int main()
{
    //A=65, Z=90//
    int numero,base;
    printf("Digite o numero inteiro positivo\n");
    scanf("%d",&numero);
    printf("Digite uma base de 2 a 36\n");
    scanf("%d",&base);
    Pilha P = pilha(numero);
    do
    {
        empilha(numero%base,P);
        numero=numero/base;
    } while ((numero) !=0 );
    
    if (base >=11)
    {
        printf("\nA base escolhida foi: %c",base+54);
    }
  
    else
    {
        printf("\nA base escolhida foi: %d" ,base);
    }
    printf("\nO número na base escolhida: ");
    while (!vaziap(P))
    {
        printf("%d",desempilha(P));
    }
    printf("\n");
    

    return 0;
}