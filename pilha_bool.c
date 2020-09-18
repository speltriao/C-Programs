#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "pilha.h"
#define True 1
#define False 0
int prioridade(char sinal)
{
   switch( sinal ) 
   {
        case '(': return 0;
        case '!': return 1; 
        case '&': return 2;
        case '|': return 3;
   }
   return -1;

}

char *posfixa2(char e[])   //Parenteseada OU não!!//
{
    static char s[256];
    int j = 0;
    Pilha P = pilha(256);
    for(int i=0; e[i]; i++)
    {
        if( e[i]=='(' )
        {
            empilha('(',P);
        } 
        else if(strchr("VF",e[i]))
        {
            s[j++] = e[i];
        } 
        else if( strchr("!&|",e[i]) ) 
        {
            while( !vaziap(P) && (prioridade(topo(P))>=prioridade(e[i])) ) 
            {
                s[j++] = desempilha(P);
            }
            empilha(e[i],P);
        }
        else if( e[i] == ')' ) 
        {
            while( topo(P)!='(' ) 
            { 
                s[j++] = desempilha(P);
            }
            desempilha(P);
      } 
    }         
    while( !vaziap(P) )
    {
        s[j++] = desempilha(P);
    }
    s[j] = '\0';
    destroip(&P);
    return s;
}

char *posfixa1(char *e) { //Parenteseada//
   static char s[256];
   int j = 0;
   Pilha P = pilha(256);
   for(int i=0; e[i]; i++)
   {
      if(strchr("VF",e[i]))
      {
          s[j++] = e[i];
      } 
      else if( strchr("!&|",e[i]) ) 
      {
          empilha(e[i],P);
      }
      else if( e[i]==')' )
      {
          s[j++] = desempilha(P);
      } 
   }
   s[j] = '\0';
   destroip(&P);
   return s;
}


int calcular_pos(char e[])
{
    int tamanho=strlen(e);
    int aux,aux2;
    Pilha P = pilha(tamanho);
    for (int i = 0; i < tamanho; i++)
    {
        if( strchr("V",e[i]) ) 
        {
            empilha(1,P);
        }
        else if( strchr("F",e[i]) ) 
        {
            empilha(1,P);
        }
        else if( strchr("!",e[i]) ) 
        {
            aux=desempilha(P);
            if (aux==1)
            {
                empilha(0,P);
            }
            else
            {
                empilha(1,P);
            }
        }
        else if( strchr("|",e[i]) )
        {
            aux=desempilha(P);
            aux2=desempilha(P);
            empilha((aux)||(aux2),P);
        }
        else if( strchr("&",e[i]) )
        {
            aux=desempilha(P);
            aux2=desempilha(P);
            empilha((aux)&&(aux2),P);
        }
      
    }
    return(desempilha(P));
}

int main()
{
    puts("A expressão original é: \"((!F)|(F&V))\"");
    printf("A expressão na posfixa é: ");
    puts(posfixa1("((!F)|(F&V))"));
    printf("A expresão resulta em: %d",calcular_pos(posfixa1("((!F)|(F&V))")));
    //puts(posfixa2("((!F)|(F&V))"));
    return 0;
}