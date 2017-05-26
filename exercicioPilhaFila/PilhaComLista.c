#include <stdlib.h>
#include <stdio.h>

typedef struct listano ListaNo;
typedef struct pilha Pilha;

struct listano {
	
	float info;
	ListaNo* prox;
	
};

struct pilha {
	
	ListaNo* prim;
	
	
	
};


Pilha* pilha_cria (void) {
	
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	p -> prim = NULL;
	return p;
	
	
	
	
}


void pilha_push (Pilha* p, float v) {
	
	
	ListaNo* n = (ListaNo*) malloc (sizeof(ListaNo));
	n -> info = v;
	n -> prox = p -> prim;
	p -> prim = n;
	printf ("Inserindo %.1f...\n\n", v);
	
	
}


float pilha_pop (Pilha* p) {
	
	ListaNo* t = p -> prim;
	float v = t -> info;
	p -> prim = t -> prox;
	free (t);
	printf ("\n\nRetirando %.1f...\n\n", v);
	return v;
	
	
}


int pilha_vazia (Pilha* p) {
	
	return (p -> prim == NULL);	
	
}


void pilha_libera (Pilha* p) {
	
	
	ListaNo* q = p-> prim;
	while (q !=NULL) {
		
		ListaNo* t = q -> prox;
		free (q);
		q = t;
		
	}
	
	free (p);
	
	
}

void pilha_imprime (Pilha* p) {
	
	
	for (ListaNo* q = p -> prim; q != NULL; q = q -> prox) {
		
		
		printf ("\n\n%.1f\n\n__________", q -> info);
		
	}
	
	
	
}

int main () {
	
	Pilha* p = pilha_cria();
	printf ("Vamos inserir quatro dezenas na pilha. \n\n");
	pilha_push (p, 23);
	pilha_push (p, 45);
	pilha_push (p, 56);
	pilha_push (p, 78);
	pilha_imprime (p);
	printf ("\n\nVamos retirar as dezenas, uma a uma. \n\n");
	pilha_pop (p);
	pilha_imprime (p);
	pilha_pop (p);
	pilha_imprime (p);
	pilha_pop (p);
	pilha_imprime (p);
	pilha_pop (p);
	pilha_imprime (p);
	pilha_libera (p);
	pilha_vazia (p);
	printf ("Fim do programa.\n\n");
	
	
	
	
	return 0;
}