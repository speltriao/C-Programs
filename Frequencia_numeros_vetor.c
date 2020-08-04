#include <stdio.h>

int main() {

    int n,c, aux, contador=1; //C está declarado aqui porque também será usado fora do Loop FOR//
    
    scanf("%d", &n);
    
    int vetor[n];
    
    for(int c = 0; c < n; c++)	//CRIAR VETOR E PREENCHER//
	{
    	scanf("%d", &vetor[c]);
	}
	
	for (int i = 0; i < n; i++) //DEIXAR VETOR CRESCENTE//
	{ 

		for (int j=i+1; j < n; j++)
		{
			if (vetor[i]>vetor[j])
			{
				aux=vetor[j];
				vetor[j]=vetor[i];
				vetor[i]=aux;
			
			}
			
		}
		
	}
	
	
    for(c = 0; c < n-1; c++) //Como o vetor já está em ordem crescente, é mais fácil comparar os elementos.//
							//Um elemento só será igual a um imediatamente próximo a ele, indepdente de termos
							//1 igual ou N iguais, há a certeza de que estará em suas proximidades imediatas//
	{
    	if (vetor[c] == vetor[c+1]) 
		{
			contador +=1;
		}
    	else
		{
			printf("%d aparece %d vez(es)\n",vetor[c],contador); //Printa o contador//
			contador = 1; //Reinicia  o contador//
		} 
	}
	
	printf("%d aparece %d vez(es)\n",vetor[c],contador); /*Falta imprimir o último elemento! Já que no último elemento do vetor
														Não teria como imprimir C+1 ou seja(Ultimo+1)!!!*/

														/*Garantimos já que se o último elemento for igual ao penultimo, o contador vai 
														ter somado +1 antes de sair do FOR e vai ser impresso nessa linha*/

														/*Mas se for diferente, vai funcionar também. O contador vai estar com 1 e
														vai imprimir o ultimo elemento */
	
    return 0;
}