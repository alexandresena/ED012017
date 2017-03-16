import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.Arrays;
import java.lang.Math;

public class desvioPadraoPonteiro {

	public static void desvioPadrao (int a){
		
  	  double [] valorPopulacao = new double[a];
  	  double mediaValores = 0;
  	  double totalElementos = 0;
  	  double somatorio = 0;
  	  double potencia = 0;
  	  double divisao = 0;
	  double resultado = 0;
	  	  
  	  for (int i=0; i<a; i++) {
	  	
  		  System.out.printf ("Entre com o %do valor\t", i+1);
  		  Scanner input = new Scanner (System.in);
  		  double valor = input.nextDouble ();
  		  valorPopulacao[i] = valor; 
  		  totalElementos = totalElementos + valor;
  		  mediaValores = (mediaValores + valor)/(i+1);
  		  potencia = Math.pow ((valor - mediaValores), 2);
  		  somatorio = somatorio + potencia;
  		  divisao = somatorio / totalElementos;
		
		  
  	  }
	  
  	  resultado = Math.sqrt (divisao);
	  System.out.printf ("\nO desvio padrão é %f\t\n\n", resultado);	
	  
	  
				
		
	}


	public static void main(String[] args){    
		
		System.out.printf ("Informe o tamanho do vetor\t");
		Scanner tamanhoVetor = new Scanner (System.in);
	 	int a = tamanhoVetor.nextInt();	
		desvioPadrao (a); 		
		
	    
  }
  
}
