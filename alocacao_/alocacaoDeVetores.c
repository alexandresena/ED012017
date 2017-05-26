#include <stdlib.h>
#include <stdio.h>




void captura (int n, float x[]) {
	
	for (int i=0; i<n; ++i) {
		
		scanf ("%f", &x[i]);				
		
	}	
}

float media (int n, float x[]) {
	
	float m = 0.0f;
	for (int i=0; i<n; ++i) {
		
		m += x[i];		
		
	}	
	m /= n; 
	return m;
}



float variancia (int n, float x[], float m) {
	
	
	float v = 0.0f;
	for (int i=0; i<n; ++i) {
		
		v += (x[i] - m) *  (x[i] -m);
		
		
		
	}
	
	v  /= n;
	return v;
	
}




int main (void) {
	
	int n; /* número de valores */
	
	
	/* lê número de valores*/
	
	printf ("Entre com o número de valores.\t");
	scanf ("%d", &n);
	float *x = (float*) malloc (n * sizeof(float)); /* Alocação dinâmica do vetor x */
	if (x==NULL) {
		
		printf ("Memória insuficiente.\n");
		exit (1); /* Aborta o programa */
		
	}
	
	captura (n,x);
	float m = media (n,x);
	float v = variancia (n,x,m);
	printf ("Média: %f\nVariancia: %f\n", m, v);	
	return 0;
}