/* Este programa foi feito seguindo instruções do livro do Waldemar Celes - Introdução à Estrutura de Dados. */



#include <stdlib.h>
#include <stdio.h>

typedef struct lista Lista;
typedef struct listano ListaNo;

/* Lista em si, apontando para os ponteiros do primeiro e do último nó. */

struct lista {
	
	ListaNo* prim;
	ListaNo* ult;		
	
};

/* Estrutura que representa o nó da lista é autorreferenciada - possui campo com ponteiro para a próxima estrutura e a estrutura anterior do mesmo tipo. */

struct listano {
	
	int info;
	ListaNo* ant;
	ListaNo* prox;
	
};



/* Função de criação: retorna uma lista inicialmente vazia. */

Lista *lst_cria (void) {
	
	Lista* l = (Lista*) malloc (sizeof(Lista));
	l -> prim = NULL;
	l -> ult = NULL;
	return l;	
	
}


/* Função que imprime os valores de uma lista. */


void lst_imprime (Lista* l) {
	
	
	for (ListaNo* p = l -> prim; p != NULL; p = p -> prox) {
		
		printf ("Info = %d\t", p->info);
				
	}
	
	printf ("\n\n");
	
}


/* Função de inserção no início da lista. */

void lst_insere_inicio (Lista* l, int v) {
	
	ListaNo* novo = (ListaNo*) malloc (sizeof(ListaNo));
	novo -> info = v;
	novo -> prox = l -> prim; /* Próximo de 'novo' é o antigo 'primeiro'. */
	novo -> ant = NULL; /* Anterior é nulo ('novo' é o primeiro elemento). */
	
	 if (l -> prim != NULL) {  /* Testa se a lista não está vazia. */
		
		l -> prim -> ant = novo;  /*'Novo' é o anterior do antigo 'primeiro'. */
					
	}
	
	else { /* Se a lista estiver vazia. */
		
		l -> ult = novo; /* 'Novo' também é último. */
				
	}		
	
	l -> prim = novo; /* 'Novo' é o primeiro. */
	printf ("\nInserindo %d...\n", v);
	lst_imprime (l); 
	
}


/* Função de inserção no final da lista. */

void lst_insere_final (Lista* l, int v) {
	
	ListaNo* novo = (ListaNo*) malloc (sizeof(ListaNo));
	novo -> info = v;
	novo -> ant = l -> ult; /* Anterior de 'novo' é o antigo 'último'. */
	novo -> prox = NULL; /* Próximo é nulo ('novo' é o último elemento.) */
	
	if (l -> ult != NULL) { /* Testa se a lista não está vazia */
		
		l -> ult -> prox = novo; /* 'Novo' é o próximo do antigo 'último'. */
				
	}
	
	else {
		
		l -> prim = novo; /* 'Novo' também é o primeiro. */
			
	}
	
	l -> ult = novo; /* 'Novo' é o último. */
	printf ("\nInserindo %d...\n", v);
	lst_imprime (l); 
	
}	


/* Função que busca um elemento na lista. */

ListaNo* lst_busca (Lista* l, int v) {
	
	for (ListaNo *p = l -> prim; p!=NULL; p = p -> prox) {
		
		if (p -> info == v) {
			
			printf ("\n%d está na lista.\n",v);
			return p; /* Achou o elemento na lista */
			
		}
	
		
	}
	
	printf ("\n%d não está na lista.\n",v);
	return NULL; /* Não achou o elemento na lista. */
	
	
}











/* Função Retira: retira elemento da lista. */


void lst_retira (Lista* l, int v) {
	
	
	ListaNo* p = lst_busca (l, v); /* Ponteiro para percorrer a lista. */
	

	/* Verifica se achou o elemento. */
	
	if (p == NULL) {
		
		return;
		
	}
	
	
	if (p == l -> prim) { /* Testa se é o primeiro elemento. */
		
		l -> prim = p -> prox; /* Atualiza o primeiro elemento. */
		
		
	}
	
	else {
		
		p -> ant -> prox = p -> prox; /* Faz o próximo apontar para o anterior. */
		
		
	}
	
	
	if (p == l -> ult) { /* Testa se é o último elemento. */
		
		l -> ult = p -> ant; /* Atualiza o último elemento. */		
		
	}
	
	else {
		
		p -> prox -> ant = p -> ant; /* Faz o anterior apontar para o próximo. */
		
		
	}
		
	printf ("\nRetirando %d...\n", v);
	free (p); /* Libera elemento (nó). */
		
		
	
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
	printf ("Vamos inserir quatro dezenas na lista. Cada dezena é inserida no INICIO da lista.\n\n");
	lst_insere_inicio (l, 1);
	lst_insere_inicio (l, 2);
	lst_insere_inicio (l, 3);
	lst_insere_inicio (l, 4); 
	
	printf ("Vamos inserir mais quatro dezenas na lista. Agora, cada dezena é inserida no FINAL da lista.\n\n");
	lst_insere_final (l, 5);
	lst_insere_final (l, 6);
	lst_insere_final (l, 7);
	lst_insere_final (l, 8);
	
	printf ("Conferindo os elementos que estão na lista. Informando os oito que estão na lista e mais dois (9 e 10) que nào estão.\n\n");
	lst_busca (l, 1);
	lst_busca (l, 2);
	lst_busca (l, 3);
	lst_busca (l, 4);
	lst_busca (l, 5);
	lst_busca (l, 6);
	lst_busca (l, 7);
	lst_busca (l, 8);
	lst_busca (l, 9);
	lst_busca (l, 10);

	
	printf ("\n\nFim do programa.\n\n");
	lst_libera (l);
	
	
	return 0;
	
}
