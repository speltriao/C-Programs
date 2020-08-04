#include<stdio.h>
main(){
    
    char hexa[4]={};
    int entrada,aux,numero,i,contador;
    entrada=0;
    while (entrada<1 || entrada>65535)
    {
        printf("\n Digite um numero inteiro entre 1 e 65.535 \n");
        scanf("%i",&entrada); 
    }

    contador=3;
    numero=entrada;
    while (numero != 0){
            if (numero%16==10){
                hexa[contador]=('A');
            }
            else if (numero%16==11){
                hexa[contador]=('B');
            }
            else if (numero%16==12){
                hexa[contador]=('C');
            }
            else if (numero%16==13){
                hexa[contador]=('D');
                }
            else if (numero%16==14){
                hexa[contador]=('E');
                }
            else if (numero%16==15){
                hexa[contador]=('F');
                }
            else{
                aux = numero%16;
                hexa[contador]=(aux +'0');
                }
            contador-=1;
            numero=numero/16;
            }

        for (i = 0; i <= 3; i++)
        {
            printf("%c",hexa[i]);
        }
        
}
