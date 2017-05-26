/* Este programa foi feito seguindo instruções do livro do Waldemar Celes - Introdução à Estrutura de Dados. */



#include <stdlib.h>
#include <stdio.h>

typedef struct lista Lista;
typedef struct listano ListaNo;

/* Lista em si, apontando para o ponteiro do primeiro nó. */

struct lista {
	
	ListaNo* prim;		
	
};

/* Estrutura que representa o nó da lista é autorreferenciada - possui campo com ponteiro para uma próxima estrutura do mesmo tipo. */

struct listano {
	
	int info;
	ListaNo* prox;
	
};



/* Função de criação: retorna uma lista inicialmente vazia. */

Lista *lst_cria (void) {
	
	Lista* l = (Lista*) malloc (sizeof(Lista));
	l -> prim = NULL;
	return l;	
	
}


/* Função de inserção no início da lista. */

void lst_insere (Lista* l, int v) {
	
	ListaNo* novo = (ListaNo*) malloc (sizeof(ListaNo));
	novo -> info = v;
	novo -> prox = l -> prim;
	l -> prim = novo;
	printf ("Inserindo %d...\n\n", v);
	
}

/* Função que imprime os valores de uma lista. */


void lst_imprime (Lista* l) {
	
	
	for (ListaNo* p = l -> prim; p != NULL; p = p -> prox) {
		
		printf ("Info = %d\t", p->info);
				
	}
	
	printf ("\n\n");
}


/* Função Pertence: verifica se um elemento está na lista. */

int pertence (Lista* l, int v){
	
	for (ListaNo* p = l -> prim; p != NULL; p = p->prox) {
		
		
		if (p->info == v) {
			
			printf ("%d pertence à lista.\n\n", v);
			return 1; /* Encontrou o elemento. */
			
			
		}
	
		
	}
	
	printf ("%d não pertence à lista.\n\n", v);
	return 0; /* Não encontrou o elemento. */	
	
}

/* Função Insere Ordenado: insere elemento em ordem. */


void lst_insere_ordenado (Lista* l, int v){
	
	ListaNo* ant = NULL; /* Ponteiro para elemento anterior. */
	ListaNo* p = l->prim; /* Ponteiro para percorrer a lista. */
	
	/* Localiza posição de inserção. */
	while (p != NULL && p -> info < v) {
		
		ant = p;
		p = p -> prox;
						
	}
	
	/* Cria novo elemento. */
	
	ListaNo* novo = (ListaNo*) malloc (sizeof(ListaNo));
	novo -> info = v;
	
	
	/* Encadeia elemento. */
	
	if (ant == NULL) {
		
		/* Insere elemento no início. */
		
		novo -> prox = l-> prim;
				
		
	}
	
	else {
		
		/* Insere elemento no meio da lista. */
		
		novo -> prox = ant -> prox;
		ant -> prox = novo;
		
	}
	
	printf ("Inserindo %d...\n\n", v);
	
}

/* Função Retira: retira elemento da lista. */


void lst_retira (Lista* l, int v) {
	
	ListaNo* ant = NULL; /* Ponteiro para elemento anterior. */
	ListaNo* p = l -> prim; /* Ponteiro para percorrer a lista. */
	
	/* Procura elemento na lista, guardando o anterior. */
	while (p != NULL && p->info != v) {
		
		ant = p;
		p = p -> prox;
		
		
	}
	
	/* Verifica se achou o elemento. */
	if  (p != NULL) {
		
		/* Retira o elemento. */
		
		if (ant == NULL) {
			
			/* Retira elemento do início. */
			
			printf ("Retirando %d...\n\n", v);
			l -> prim = p -> prox;
			
			
		}
		
		else {
			
			/* Retira elemento do meio da lista. */
			
			printf ("Retirando %d...\n\n", v);
			ant -> prox = p -> prox;
			
		}
		
		free (p); /* Libera elemento (nó). */
		
		
	}
	
	
	
}


/* Função Vazia: retorna 1 se a lista está vazia ou 0 se a lista não está vazia. */

int lst_vazia (Lista* l){
	
	return (l -> prim == NULL);
	
}

/* Função que "destrói" a lista, liberando todos os elementos alocados. */

void lst_libera (Lista* l) {
	
	ListaNo* p = l -> prim;
	
	while (p != NULL) {
		
		ListaNo* t = p -> prox; /* Guarda a referência para o próximo elemento. */
		free (p); /* Libera a memória apontada por "p". */
		p = t; /* Faz "p" apontar para o próximo elemento. */
		
	}
	
	free (l);	
	
}



int main () {
	

	Lista* l = lst_cria();
	printf ("Vamos inserir quatro dezenas na lista. Cada dezena é inserida no início da lista.\n\n");
	lst_insere (l, 23);
	lst_insere (l, 45);
	lst_insere (l, 56);
	lst_insere (l, 78);
	lst_imprime (l);
	pertence (l,45);
	lst_retira (l,78);
	lst_imprime (l);
	lst_retira (l,56);
	lst_imprime (l);
	lst_retira (l,45);
	pertence (l,45);
	lst_imprime (l);
	printf ("Vamos inserir as mesmas dezenas, agora respeitando a ordem numérica.\n\n");
	lst_insere_ordenado (l, 45);
	lst_insere_ordenado (l, 56);
	lst_insere_ordenado (l, 78);
	lst_imprime (l);
	
	printf ("\n\nFim do programa.\n\n");
	
	return 0;
	
}