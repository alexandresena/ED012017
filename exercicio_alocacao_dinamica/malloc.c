#include <stdio.h>
#include <stdlib.h>

int main () {
	
	int *vetor = (int*) malloc (12 *sizeof (int));
	int i, j;
	
	for (i=0; i<12; i++) {
					
		printf ("\nInforme o %do número.\t", i+1);
		scanf ("%d", &vetor[i]);
		
	}
	
	printf ("\nA matriz gerada é:\n\n");
	
	for (j=0; j<12; j++) {
	
		printf ("%d\t%d\t%d\t%d\n\n", vetor[j], vetor[j+1], vetor[j+2], vetor[j+3]);
		j = j+3;
			
	}
		
	
	printf ("Fim do programa.\n");
	
		
	return 0;
}