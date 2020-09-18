#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "pilha.h"


int calcular_pos(char entrada[])
{
    int aux;
    int tamanho=strlen(entrada);
    
    Pilha P = pilha(tamanho);
    
    for (int i = 0; entrada[i]; i++)
    {
        if (isdigit(entrada[i]))
        {
            
            aux = entrada[i]-'0';
            empilha(aux,P);
        }
        else if (strchr("+",entrada[i]))
        {
            aux=desempilha(P);
            aux+=desempilha(P);
            empilha(aux,P);
        }
        else if (strchr("-",entrada[i]))
        {
            aux=desempilha(P);
            aux=desempilha(P)-aux;
            empilha(aux,P);
        }
        else if (strchr("*",entrada[i]))
        {
            aux=desempilha(P);
            aux*=desempilha(P);
            empilha(aux,P);
        }
        else if (strchr("/",entrada[i]))
        {
            aux=desempilha(P);
            aux=desempilha(P)/aux;
            empilha(aux,P);
        }

        
    }
    return(desempilha(P));
    destroip(&P);

}
int prio(char o) {
   switch( o ) {
      case '(': return 0;
      case '+': 
      case '-': return 1;
      case '*': 
      case '/': return 2;
   }
   return -1; // operador inválido!
}

char *posfixa(char *e) {
   static char s[256];
   int j = 0;
   Pilha P = pilha(256);
   for(int i=0; e[i]; i++)
   {
      if( e[i]=='(' )
      {
          empilha('(',P);
      } 
      else if( isdigit(e[i]) )
      {
          s[j++] = e[i];
      } 
      else if( strchr("+-/*",e[i]) ) 
      {
         while( !vaziap(P) && prio(topo(P))>=prio(e[i]) ) 
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


int main()
{
    //calcular_pos("23*84/+");
    puts("A forma posifixa é:");
    puts(posfixa("(2*3)+(8/4)"));
    printf("E resulta: %d \n",calcular_pos(posfixa("(2*3)+(8/4)")));
    return 0;
}