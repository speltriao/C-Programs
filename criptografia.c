#include<conio.h>//Necessário para Compiladores como Pelles, mas não necessário para GCC//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define limite 20
int main()
{



    char mascara[limite];
    printf("Digite a mascara\n");
    gets(mascara);
    int tamanho=strlen(mascara);

    char nome[limite];
    printf("Digite o nome do arquivo a ser aberto, completo(com extensão). Deve estar na mesma pasta que esse programa\n");
    gets(nome);


    FILE *arquivo;
    arquivo=fopen(nome,"br"); 
    char caracter=getc(arquivo);
    int comparador;
    int contador=0;
	
	
	char nome_saida[limite];
    char crp[]=".crp";
    printf("Digite o nome do arquivo de saida SEM extensão. Terá obrigatoriamente extensão .crp\n");
    gets(nome_saida);
    strcat(nome_saida,crp);
    puts(nome_saida);
    FILE *arquivo_saida;
    arquivo_saida=fopen(nome_saida,"bw+");

    while (caracter != EOF)
    {
        comparador = caracter ^ mascara[contador];
        fputc(comparador,arquivo_saida);

        /*fprintf(arquivo_saida,"%c",mascara[contador]);
        fprintf(arquivo_saida,"%c",caracter);
        fprintf(arquivo_saida,"%c\n",comparador);*/
        if (contador == (tamanho-1))
        {
            contador=-1;
            
        }

        contador+=1;
        
        caracter=getc(arquivo);
    }
    fclose(arquivo);
    fclose(arquivo_saida);
    printf("Arquivo criptografado com sucesso!Foi Gerado um arquivo com nome: ");
    puts(nome_saida);
    printf("\n");
    return 0;
}