#include<stdio.h>
int input(){
    int entrada=0;
    while (entrada<1 || entrada>65535)
    {
        printf("\n Digite um numero inteiro entre 1 e 65.535 \n");
        scanf("%i",&entrada); 
    }
}
int impressora(int vetor[],int contador,int entrada){
    printf("O número %d em binário vale:\n",entrada);
    for (int i = contador+1; i < 16; i++){
	    printf("%d", vetor[i]);
    }
    printf("\n");
  }
int main(int entrada)
{
    int bin[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int numero,contador;
    contador=15;
    numero=entrada;
    while (numero !=0){
        if (numero %2 == 1)
        {
            bin[contador]=1;
            contador-=1;
        }
        else
        {
            contador-=1;
        }
        numero=numero/2;
    }
    impressora(bin,contador,entrada);
    return 0;
}
