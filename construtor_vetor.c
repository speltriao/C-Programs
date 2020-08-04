#include<stdio.h>

int *construtor(){
    static int vetor[3];
    for (int i = 0; i < 3; i++)
    {
        printf("Digite");
        scanf("%d",&vetor[i]);
    }
   return vetor;
}

int impressora(int *arr){
    for (int i = 0; i < 3; i++)
    {
        printf("%d\n",arr[i]);
    }
}

int main(){
    int *lista;
    lista=construtor();
    impressora(lista);
    return 0;
}