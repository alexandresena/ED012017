/* Aluno: Alexandre Gomes Sena - Matrícula: 16/0056969 */
/* Utilizei estrutura de lista duplamente encadeada, para que se possa comparar um elemento com o seu anterior, na hora de fazer a ordenação */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int contador = 0; /* Conta a quantidade total de elementos da lista */
typedef struct lista Lista;
typedef struct listano ListaNo;

/* Lista em si, apontando para os ponteiros do primeiro e último nós. */

struct lista {
	
	ListaNo* prim;		
	ListaNo* ult;
};

/* Estrutura que representa o nó da lista é autorreferenciada - possui campos com ponteiros para a próxima estrutura e a estrutura anterior do mesmo tipo. */

struct listano {
	
	char nome [51];
	char email [51];
	char telefone [16];
	ListaNo* ant;
	ListaNo* prox;
	
};

/* Funcao para limpar a tela */

void limpatela () {

#ifdef WIN32
	system ("cls");
#else	
	system ("clear");	
#endif
		
}

/* Função de criação: retorna uma lista inicialmente vazia. */

Lista *cria (void) {
	
	Lista* l = (Lista*) malloc (sizeof(Lista));
	l -> prim = NULL;
	l -> ult = NULL;
	return l;	
	
}

/* Função de inserção na lista. */

void insere (Lista* l, char* n, char* e, char* t) {
	
	ListaNo* novo = (ListaNo*) malloc (sizeof(ListaNo));
	strcpy (novo -> nome, n);
	strcpy (novo -> email, e);
	strcpy (novo -> telefone, t);
	novo -> prox = l -> prim; /* Próximo de 'novo' é o antigo 'primeiro'. */
	novo -> ant = NULL; /* Anterior é nulo ('novo' é o primeiro elemento). */
	
 	if (l -> prim != NULL) {  /* Testa se a lista não está vazia. */
	
		l -> prim -> ant = novo;  /*'Novo' é o anterior do antigo 'primeiro'. */
				
	}

	else { /* Se a lista estiver vazia. */
	
		l -> ult = novo; /* 'Novo' também é último. */
			
	}	
	
	l -> prim = novo;
	contador = contador + 1;
		
}

/* Função para editar contato. */

int edita (Lista* l, char* n){
		
	for (ListaNo* p = l -> prim; p != NULL; p = p->prox) {
	
		char* condicao = strstr (p -> nome, n); /* Compara nome passado por ponteiro com nome constante no elemento da lista */	
		
		if (condicao != NULL) {
			char e [51];
			char t [16];
			printf ("\nEditando contato %s\n\n", n);
			printf ("\n\nE-mail (sem espaços):\t");
			scanf ("%s", e);
			strcpy (p -> email, e);
			printf ("\n\nTelefone (sem espaços):\t");
			scanf ("%s", t);
			strcpy (p -> telefone, t);
			return 1;
						
		}
				
	}
	
	printf ("Contato não encontrado.\n\n");
	return 0; /* Não encontrou o elemento. */	
	
}

/* Função para ordenar contatos. */

void ordena (Lista* l) {
	
	ListaNo* p = (ListaNo*) malloc (sizeof(ListaNo)); /* Ponteiro para percorrer a lista */
	ListaNo* temp = (ListaNo*) malloc (sizeof(ListaNo));  /* Ponteiro para guardar temporariamente elemento */	
	int i = 0, j;	
	
	for (j = 1; j <= contador; j++) { /* Percorre a lista "j" vezes até ordenar todos os elementos */
		
		for (p = l -> prim; p != NULL; p = p -> prox) { /* Loop para percorrer a lista encadeada. */

			i = i + 1;
		
			if (i > 1) { /* Para evitar segmentation fault, só compara quando ponteiro estiver a partir do segundo elemento */
			
				int condicao = strcmp (p -> ant -> nome, p -> nome); /* Compara lexicograficamente os nomes de dois contatos */
				if (condicao > 0) { /* Se o nome anterior for lexicograficamente maior que o nome atual */
			
					strcpy (temp -> nome, p -> ant -> nome);
					strcpy (temp -> email, p -> ant -> email);
					strcpy (temp -> telefone, p -> ant -> telefone);	
					strcpy (p -> ant -> nome, p -> nome);
					strcpy (p -> ant -> email, p -> email);
					strcpy (p -> ant -> telefone, p -> telefone);
					strcpy (p -> nome, temp -> nome);
					strcpy (p -> email, temp -> email);
					strcpy (p -> telefone, temp -> telefone);
										
				}			
			
			}		
							
		}
		
		i = 0; /* Para evitar segmentation fault na nova varredura da lista */
				
	}
	
}



/* Função que imprime os valores de uma lista. */

void imprime (Lista* l) {
	
	printf ("Contatos:\n\n");
	
	for (ListaNo* p = l -> prim; p != NULL; p = p -> prox) {
				
		printf ("%-50s\t%-50s\t%s\n", p -> nome, p -> email, p -> telefone);
				
	}
	
	printf ("\n\n");
}

/* Função de busca. */

int busca (Lista* l, char* n){
	
	int i = 0;
	printf ("\n\n");
	
	for (ListaNo* p = l -> prim; p != NULL; p = p->prox) {
		
		char* condicao = strstr (p -> nome, n); /* Compara nome passado por ponteiro com nome constante no elemento da lista */
		
		if (condicao != NULL) {
			
			printf ("%-50s\t%-50s\t%s\n", p -> nome, p -> email, p -> telefone);
			i = i + 1;
						
		}
			
	}
	
	if (i == 0) {
		
		printf ("\nContato não encontrado.\n\n");
		
	}
	
	else if (i == 1) {
		
		
		printf ("\nFoi encontrado 1 contato.\n\n");
	}
	
	else {
		
		printf ("\nForam encontrados %d contatos.\n\n", i);
		
	}

	return 0; 
	
}

/* Função que retira elemento da lista. */

void retira (Lista* l, char* n) {
	
	for (ListaNo* p = l -> prim; p != NULL; p = p->prox) {
		
		char* condicao = strstr (p -> nome, n); /* Compara nome passado por ponteiro com nome constante no elemento da lista */
		

		/* Verifica se achou o elemento. */
	
		if (p == NULL) {
		
			printf ("Contato não encontrado.\n\n");
			return;
		
		}
		
		if (condicao != NULL) { /* Caso tenha encontrado o elemento. */
			
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
		
			free (p); /* Libera elemento (nó). */
			
			
			
		}
		
	
	}	
	
}

	

/* Função que "destrói" a lista, liberando todos os elementos alocados. */

void libera (Lista* l) {
	
	ListaNo* p = l -> prim;
	
	while (p != NULL) {
		
		ListaNo* t = p -> prox; /* Guarda a referência para o próximo elemento. */
		free (p); /* Libera a memória apontada por "p". */
		p = t; /* Faz "p" apontar para o próximo elemento. */
		
	}
	
	free (l);	
	
}

/* Função principal */

int main () {
		
	limpatela ();
	Lista* l = cria();
	char n [101], e [51], t [16];
	int opt;
	
	do {
				
		printf ("Escolha a opção\n\n");
		printf ("1. Inserir novo contato.\n");
		printf ("2. Editar contato existente.\n");
		printf ("3. Ordenar contatos.\n");
		printf ("4. Listar contatos.\n");
		printf ("5. Buscar um contato.\n");
		printf ("6. Retirar contato.\n");
		printf ("0. Zerar a lista de contatos e sair do programa.\n\n");
		printf("Opção: "); scanf("%d", &opt);

		switch (opt) {
 	
			case 1:
				limpatela ();
				printf ("Nome:\t");
				getchar();
				scanf ("%[^\n]s%*c", n);
				printf ("\n\nE-mail (sem espaços):\t");
				scanf ("%s", e);
				printf ("\n\nTelefone (sem espaços):\t");
				scanf ("%s", t);
				insere (l, n, e, t);
				printf ("\n\nContato %s inserido com sucesso.\n\n", n);			 
			break;
	
			case 2:	
				limpatela ();
				printf ("Informe o nome do contato a ser editado.\n");
				printf ("Nome:\t");
				getchar();
				scanf ("%[^\n]s%*c", n);
				edita (l, n);
				printf ("\n\nContato %s editado com sucesso.\n\n", n);	 
			break;
	
			case 3:
	 	   		limpatela ();
				ordena (l);
				printf ("A lista de contatos foi ordenada alfabeticamente.\nUtilize a opção 4 para exibir a lista.\n\n");
			break;
	
			case 4:
				limpatela ();
				imprime (l); 
			break;
	
			case 5:
				limpatela ();
				printf ("Informe o nome do contato a ser procurado.\n");
				printf ("Nome:\t");
				getchar();
				scanf ("%[^\n]s%*c", n);
				busca (l, n); 
			break;
	
			case 6:
				limpatela ();
				printf ("Informe o nome do contato a ser retirado.\n");
				printf ("Nome:\t");
				getchar();
				scanf ("%[^\n]s%*c", n);
				retira (l, n);
				printf ("Contato %s retirado com sucesso.\n\n", n); 
			break;
	
			case 0:
				libera (l);
			break;
		
			default:	
			printf ("Comando inválido\n\n;");	
	
		}
				
	} while (opt);
	
	
	printf ("FIM DO PROGRAMA.\n\n");
	return 0;
	
}