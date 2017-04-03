#include <stdlib.h>
#include <stdio.h>


typedef struct {
	
	int num;
	struct Pilha *prox;
	
	
} Pilha;


void inicia (Pilha *STACK) {
		
	STACK->prox = NULL;	
	
	
}


int vazia (Pilha *STACK) {
	
	if (STACK->prox == NULL)
		return 1;
	else
		return 0;
	
	
	
}


Pilha *aloca (Pilha *STACK) {
	
	if (vazia(STACK)) {
		
		Pilha *NOVO = (Pilha *) malloc(sizeof(Pilha));
		int i;
		for (i=0; i<10; i++) {
			
			printf ("\nDigite o %do número da pilha.\n", i+1);
			scanf ("%d", &NOVO->num);
			Pilha *TEMP;
			TEMP = NOVO;
			printf ("\nO %do número da pilha é %d.\n", i+1, TEMP->num);
									
		}
		
	return NOVO;
		
	}	
		
}


void push (Pilha *STACK) {
	
	Pilha *NOVO = aloca();
	NOVO->prox = NULL;
	
	
	
	
	
}


Pilha *pop(Pilha *STACK) {
 
 
 if (vazia (STACK)) {
  printf("\nPilha já está vazia\n\n");
  return NULL;
 }
 
 else {
  Pilha *ultimo = STACK->prox,
              *penultimo = STACK;

  while (ultimo->prox != NULL){
   penultimo = ultimo;
   ultimo = ultimo->prox;
  }

  penultimo->prox = NULL;
 
  return ultimo;
 }
 
}
	
		
	
int main () {
	
	Pilha *STACK = (Pilha *) malloc (sizeof(Pilha));	
	inicia (STACK);
	push (STACK);
	pop (STACK);
		
	return 0;	
	
	
}	