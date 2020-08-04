#include <stdio.h>
int impressora( int resposta);
//esse programa detecta se dois números inteiros quaisquer têm ao menos 1 algaritmo em comum//
int main(){
    int x,y,resposta,copx,copy;
    printf("\n Digite dois números \n");
    scanf("%d %d", &x,&y);
    printf("\n");
    copy=y;
    copx=x;
    resposta = 0;
    while (copx%10 !=0 && resposta == 0)
    {
        if (copx%10 == copy %10)
        {
            resposta = 1;
        }
        else if (copy%10==0)
        {
            copy=y;
            x = x / 10;
            copx=x;
        }
        else{
            copy=copy / 10;
        }
        
    }
    
    return impressora(resposta);
    
}
int impressora( int resposta){
    if (resposta == 0)
    {
        printf("False");
    }
    else
    {
        printf("True");
    }
    return 0;

}