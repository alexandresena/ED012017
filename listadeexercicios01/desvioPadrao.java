import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.Arrays;
import java.lang.Math;

public class desvioPadrao {

  public static void main(String[] args){
    
	  double [] valorPopulacao = new double[10];
	  double mediaValores = 0;
	  double totalElementos = 0;
	  double somatorio = 0;
	  double potencia = 0;
	  double divisao = 0;
	  	  
	  for (int i=0; i<10; i++) {
	  	
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
	  
	  double desvioPadrao = Math.sqrt (divisao);
	  System.out.println ("O desvio padrão é");
	  System.out.printf ("%f\n", desvioPadrao);
	    
  }
  
}
