#include <stdio.h>

int crescente(int x,int y ){return (x>y);}

int decrescente(int x,int y ){return (y>x);}

void troca(int v[], int i, int j) {
   int x = v[i];
   v[i] = v[j];
   v[j] = x;
}
void empurra(int v[],int u)
{
    if (u==0) return;
    empurra(v,u-1);
    if(v[u-1]> v[u]) troca(v,u-1,u);
    
}
void exibe(int v[],int tamanho)
{
    for (int i = 0; i < tamanho; i++){
        printf("[%d] ",v[i]);
    }
    printf("\n");
}
void bsort_original(int v[], int n) { 
   for(int i=1; i<=n; i++){ //Bubble sort//
      for(int j=0; j<n-i; j++){
         if( (v[j]>v[j+1]) ){
            troca(v,j,j+1);}
        }
    }
}
void bsort (int (*f) (int,int),int v[], int n){
    for (int i = 1; i < n; i++){ //f = crescente ou decrescente
        for (int j = 0; i < n-1; j++){
            if (f(v[j],v[j+1])){
                troca(v,j,j+1);
            }
        }
    }
}
void bsr(int v[], int n) //Bubble sort recursivo//
{
    exibe(v,5);
    if(n==1) return;
    empurra(v,n-1);
    bsr(v,n-1);
    
}
int main()
{
    int vetor[5]={12,21,33,4,1};

    //empurra(vetor,5);
    bsr(vetor,5);


    return 0;
}