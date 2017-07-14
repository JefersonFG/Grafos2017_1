#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct Stack * initializeStack(){
	struct Stack * s;

	s = NULL;
	return s;
}
	
int isEmptyStack(struct Stack * s){
	if (s == NULL)
		return 1;
	else
		return 0;
}


struct Stack * pushStack(struct Stack * s, int x){
	struct Stack * aux;
	struct Stack * new;


   new = (struct Stack*) malloc(sizeof(struct Stack));
   new->next = NULL;

   new->data = x;

   new->next = s;
   s = new;
   return s;
}


int popStack (struct Stack **s, int *x)
{
   struct Stack* aux;

   if (isEmptyStack(*s))
     return 0;
   else
   {
        *x = (*s)->data;
        aux = *s;
        *s = (*s)->next;
        free(aux);
        aux=NULL;
        return 1;
   }
}