#include <stdio.h>
#include <stdlib.h>
typedef struct node *List;
struct node {
    int item;
    List next;};

List node(int item, List next) {
    List new = malloc(sizeof(struct node));
    new->item = item;
    new->next = next;
    return new;
}
List reversed_range(int a, int b){
    if(a>b) return NULL;
    else if (a==b) return node(a,NULL);
    else return (node(b,reversed_range(a,b-1)));
}

void print(List L) {
    printf("[");
    while( L ) {
        printf("%d", L->item);
        if( L->next ) printf(",");
    L = L->next;
    }
    printf("]\n");
}

int decreasing (List L){
     while (L != NULL)
    {
        int aux=L->item;
        L = L->next;
        if (L == NULL) break;
	if (aux<=(L->item)) return 0;
    }
    return 1;
}
int main(void) {
    printf("%d\n", decreasing(NULL)); // deve exibir 1
    printf("%d\n", decreasing(node(7,NULL))); // deve exibir 1
    printf("%d\n", decreasing(node(5,node(3,node(4,NULL))))); // deve exibir 0
    printf("%d\n", decreasing(node(9,node(7,node(5,NULL))))); // deve exibir 1
    printf("%d\n", decreasing(node(9,node(8,node(7,node(7,NULL)))))); // deve exibir 0
return 0;
}