#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define limite 100
#define True 1
#define False 0
 /*Apenas o item no topo da pilha pode ser acessado ou removido. É o último a ter entrado e o primeiro a sair*/

typedef struct estrtura_pilha //Typedef cria um novo tipo de variável, diferente de char, int, float, etc. Aqui estamos criando o tipo "Pilha"//
{//estrutura_pilha é uma tag (opcional) que podemos dar para a estrutura//
	int vetor[limite];
	int topo; //Indice do vetor onde o topo está//
}Pilha;

void imprimir_topo(Pilha *ponteiro)
{
	printf("%d",ponteiro->topo);
}


void iniciar_pilha(Pilha *ponteiro) //ponteiro aponta pra Pilha, que é uma estrutura de dados//
{
	ponteiro->topo =-1;  // igual a escrever ((*ponteiro).topo)=-1. Equivalente ao PONTO(.) na struct, só que com ponteiro//
}

int isvazia(Pilha *ponteiro)
{
	if (ponteiro->topo==-1)
	{
		return(True);//está vazia//
	}
	else
	{
		return(False);//não está vazia//
	}
	
}

int ischeia(Pilha *ponteiro)
{
	if((ponteiro->topo)==(limite -1)) //Se o indice do vetor que está no topo (variável topo) for maior (limite-1), pilha está cheia//
	{
		return(True);
	}
	else
	{
		return(False);
	}
	
}

void inserir(Pilha *ponteiro, char valor[])
{
	//Primiramente verificar se a pilha tem espaço livre//
	int tamanho=strlen(valor);
	if (ischeia(ponteiro)==True)
	{
		printf("Pilha cheia");
	}
	else
	{
		for (int i = 0; i < tamanho; i++)
		{
			
			//Antes de adicionarmos o valor, precisamos aumentar o topo em 1, para caber o novo "valor"//
			ponteiro->topo = ponteiro->topo+1;
			ponteiro->vetor[ponteiro->topo]=valor[i];//recebe o novo topo ponteiro->topo+1, que foi somado 1//
		}
		
	}
}

int remover(Pilha *ponteiro)
{
	int aux;
	if (isvazia(ponteiro)==True)
	{
		printf("A pilha esta vazia");
		return False;
	}
	else
	{
		
		aux=ponteiro->vetor[ponteiro->topo]; //aux = vetor[topo] //
		ponteiro->topo = ponteiro->topo -1;//Para removemos o último valor, precisamos diminuir o topo em 1//
		return aux;
	}
}

void imprimir_pilha(Pilha *ponteiro)
{
	int tamanho=ponteiro->topo;
	for (int i=0; i <= (tamanho); i++)
	{
		printf("%c",ponteiro->vetor[i]);
	
	}
	
}

char* inverter(char entrada[]) //o asterisco em char* é devido ao fato da função retornar um ponteiro de tipo char// 
{
	Pilha *ponteiro = malloc(sizeof(Pilha));
	iniciar_pilha(ponteiro);
	inserir(ponteiro,entrada);
	int tamanho=strlen(entrada);
	char* retornar=(char*)malloc(strlen(entrada));

	for (int i=0;i<=tamanho;i++) 
	{
		retornar[i]=ponteiro->vetor[ponteiro->topo];
		ponteiro->topo=ponteiro->topo-1;
		
	}

	return(retornar); //retornar é um PONTEIRO//
}

int main()
{
	char entrada[limite];
	char *saida;
	puts("Digite a string a ser invertida");
	fgets(entrada,limite,stdin); //gets() não é recomendado. Sintaxe fgets(variavel,tamanho_maximo,stdin)//
	saida=inverter(entrada); //Salvando a string invertida numa variável//
	puts(saida);
	return 0;
}
