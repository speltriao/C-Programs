#include<stdio.h>
int impressora(int vetor[4]){
    for (int i = 0; i < 4; i++)
    {
        printf("%d \n",vetor[i]);
    }
    
}
int crescente(int vetor[4]){
    int aux;
    for (int i = 0; i < 4; i++)
    {
        for (int j = i+1; j < 4; j++)
        {
            printf("\n i=%d  j=%d",i,j);
            if (vetor[i]>vetor[j])
            {
                aux=vetor[i];
                vetor[i]=vetor[j];
                vetor[j]=aux;
            }
            
        }
        
    }
    return(vetor[4]);
}
int main()

{
    int vetor[4]={8,5,1,4};
    printf("Vetor original \n");
    impressora(vetor);
    vetor[4]=crescente(vetor);
    printf("\n\nVetor depois \n");
    impressora(vetor);
    return 0;
}
