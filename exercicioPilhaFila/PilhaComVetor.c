#include <stdlib.h>
#include <stdio.h>

typedef struct pilha Pilha;

struct pilha {
	
	int n; /* Número de elementos armazenados. */
	int dim; /* Dimensão corrente do vetor. */
	float *vet; /* Vetor dos elementos */
	
	
};


/* Função que cria a pilha: faz alocação dinâmica, escolhe uma dimensão inicial para o vetor e inicializa a pilha como sendo vazia. */
Pilha* pilha_cria (void) {
	
	Pilha* p = (Pilha*) malloc (sizeof(Pilha));
	p -> dim = 2; /* Dimensão inicial. */
	p -> vet = (float*) malloc (p->dim * sizeof(float));
	p -> n = 0; /* Inicia com zero elementos. */
	

	return p;
	
}


/* Função Push: insere um elemento na pilha, usando a próxima posição livre do vetor e verificando a necessidade de realocação. */


void pilha_push (Pilha* p, float v) {
		
	
	/* Capacidade esgotada - necessária realocação. */
	if (p->n == p->dim) { 
		
		
		p -> dim *= 2;
		p -> vet = (float*) realloc (p -> vet, p -> dim * sizeof(float));		
		
	} 
	
	/* Insere elemento na próxima posição livre. */
	
	
	p -> vet [p -> n++] = v; 
			
	
}



/* Função Pop: retira o elemento do topo da pilha, fornecendo seu valor como retorno. */

float pilha_pop (Pilha *p) {
	
	float v = p -> vet [--p -> n]; /* Retira o elemento do topo. */
	return v;	
	
	
}



int pilha_vazia (Pilha *p) {
	
	
	return (p -> n == 0);
	
	
	
}


void pilha_libera (Pilha* p) {
	
	free (p -> vet);
	free (p);
	
}


void pilha_imprime (Pilha* p, int n) {
	
	
	printf ("\n%f\n", p -> vet [n]);
			
	
}




int main () {
	
	int i, j=0, k;
	float v=0;
	Pilha* p = NULL;
	pilha_cria ();
	
	printf ("\nDigite a quantidade de números que você quer colocar na pilha.\t");
	scanf ("%d", &j);
	for (i = 0; i < j; i++) {
		
		printf ("\n%do número:\t", i+1);
		scanf ("%f", &v);
		pilha_push (p, v);
		
					
	} 

	
	
	
	
	printf ("\nA pilha está formada com os seguintes números:\n");
	
	for (i = 0; i < j; i++) {
				
		pilha_imprime (p, i);
					
	}
	
	
	printf ("\nDigite a quantidade de números que você quer retirar da pilha.\t");
	scanf ("%d", &k);
	for (i = 0; i < k; i++) {
				
		pilha_pop (p);
					
	}
	
	printf ("\nA pilha agora está formada com os seguintes números:\n");
	
	for (i = 0; i < j-k; i++) {
				
		pilha_imprime (p, i);
					
	}
	
	pilha_libera (p);
	pilha_vazia (p);
	printf ("\nFIM DO PROGRAMA.\n");
	
	
	return 0;
}