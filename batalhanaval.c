/*Estruturas de Dados - Turma B - Prof. Gustavo Van Erven*/
/*Alunos: Alexandre Sena - 16/0056969 e
  Marcos Paes da Silva  - 14/0153101*/

#include <stdio.h>
#include <stdlib.h>

void mensagemInicial(){
    printf("\n**********************UNIVERSIDADE DE BRASILIA**********************\n\n");
    printf("                                                                 \n");
    printf("     ________________________________________________________                                                                \n");
    printf("    |       ----_                                            |        \n");
    printf("    |      |     -                                           |        \n");
    printf("    |      |      -                                          |        \n");
    printf("    |      |   ---     _   ____    _                  _      |        \n");
    printf("    |      |     -    | |    |    | |   |    |   |   | |     |        \n");
    printf("    |      |      -  |_ _|   |   |_ _|  |    |- -|  |_ _|    |        \n");
    printf("    |      |_ _ _-  |     |  |  |     | |_ _ |   | |     |   |        \n");
    printf("    |                                                        |        \n");
    printf("    |                                                        |        \n");
    printf("    |                                                        |        \n");
    printf("    |                                                        |        \n");
    printf("    |         ||     |                                       |        \n");
    printf("    |         | |    |                                       |        \n");
    printf("    |         |  |   |    _             _                    |        \n");
    printf("    |         |   |  |   | |  |     |  | |   |               |        \n");
    printf("    |         |    | |  |_ _|  |   |  |_ _|  |               |        \n");
    printf("    |         |     || |     |  |_|  |     | |_ _            |        \n");
    printf("    |                                                        |        \n");
    printf("    |________________________________________________________|        \n\n");


    printf("Digite ENTER para continuar: \n");
    getchar();
}


void inicializaTabuleiro1(int tabuleiro1[][5])
{
    int linha, coluna;
        for(linha=0 ; linha < 5 ; linha++ )
            for(coluna=0 ; coluna < 5 ; coluna++ )
                tabuleiro1[linha][coluna]=-1;
}


void inicializaTabuleiro2(int tabuleiro2[][5])
{
    int linha, coluna;
        for(linha=0 ; linha < 5 ; linha++ )
            for(coluna=0 ; coluna < 5 ; coluna++ )
                tabuleiro2[linha][coluna]=-1;
}




void mostraTabuleiro1(int tabuleiro1[][5])
{

    int linha, coluna;
		printf ("\n\nJOGADOR 1\n\n");
        printf("\t1 \t2 \t3 \t4 \t5");
        printf("\n");

        for(linha=0 ; linha < 5 ; linha++ ){
            printf("%d",linha+1);
            for(coluna=0 ; coluna < 5 ; coluna++ ){
                if(tabuleiro1[linha][coluna]==-1){
                    printf(" \t~");
                }else if(tabuleiro1[linha][coluna]==0){
                    printf(" \t*");
                }else if(tabuleiro1[linha][coluna]==1){
                    printf(" \tX");
                }

            }
            printf("\n");
        }

    }

	void mostraTabuleiro2(int tabuleiro2[][5])
	{

	    int linha, coluna;
			printf ("\n\nJOGADOR 2\n\n");
	        printf("\t1 \t2 \t3 \t4 \t5");
	        printf("\n");

	        for(linha=0 ; linha < 5 ; linha++ ){
	            printf("%d",linha+1);
	            for(coluna=0 ; coluna < 5 ; coluna++ ){
	                if(tabuleiro2[linha][coluna]==-1){
	                    printf(" \t~");
	                }else if(tabuleiro2[linha][coluna]==0){
	                    printf(" \t*");
	                }else if(tabuleiro2[linha][coluna]==1){
	                    printf(" \tX");
	                }

	            }
	            printf("\n");
	        }

	    }

//Inicia os navios usando a função SRAND.

void iniciaNavios1(int navios1[][2]){
        srand(time(NULL));
        int navio, anterior;

        for(navio=0 ; navio < 3 ; navio++){
            navios1[navio][0]= rand()%5;
            navios1[navio][1]= rand()%5;


            for(anterior=0 ; anterior < navio ; anterior++){
                if( (navios1[navio][0] == navios1[anterior][0])&&(navios1[navio][1] == navios1[anterior][1]) )
                    do{
                        navios1[navio][0]= rand()%5;
                        navios1[navio][1]= rand()%5;
                    }while( (navios1[navio][0] == navios1[anterior][0])&&(navios1[navio][1] == navios1[anterior][1]) );
            }

        }
    }

void iniciaNavios2(int navios2[][2]){
	        srand(time(NULL));
	        int navio, anterior;

	        for(navio=0 ; navio < 3 ; navio++){
	            navios2[navio][0]= rand()%5;
	            navios2[navio][1]= rand()%5;


	            for(anterior=0 ; anterior < navio ; anterior++){
	                if( (navios2[navio][0] == navios2[anterior][0])&&(navios2[navio][1] == navios2[anterior][1]) )
	                    do{
	                        navios2[navio][0]= rand()%5;
	                        navios2[navio][1]= rand()%5;
	                    }while( (navios2[navio][0] == navios2[anterior][0])&&(navios2[navio][1] == navios2[anterior][1]) );
	            }

	        }
 }	


//Função que aponta para o tiro
void darTiro1(int tiro1[2])
{
		
        printf("Linha: ");
        scanf("%d",&tiro1[0]);
        tiro1[0]--;

        printf("Coluna: ");
        scanf("%d",&tiro1[1]);
        tiro1[1]--;

}

void darTiro2(int tiro2[2])
{
		
        printf("Linha: ");
        scanf("%d",&tiro2[0]);
        tiro2[0]--;

        printf("Coluna: ");
        scanf("%d",&tiro2[1]);
        tiro2[1]--;

}



// Em caso de acerto, chama essa função.
int acertou1(int tiro1[2], int navios1[][2])
{
    int navio;

        for(navio=0 ; navio < 3 ; navio++){
            if( tiro1[0]==navios1[navio][0] && tiro1[1]==navios1[navio][1]){
                printf("Você acertou o tiro (%d,%d)\n",tiro1[0]+1,tiro1[1]+1);
                return 1;
            }
        }
        return 0;
    }


	int acertou2(int tiro2[2], int navios2[][2])
	{
	    int navio;

	        for(navio=0 ; navio < 3 ; navio++){
	            if( tiro2[0]==navios2[navio][0] && tiro2[1]==navios2[navio][1]){
	                printf("Você acertou o tiro (%d,%d)\n",tiro2[0]+1,tiro2[1]+1);
	                return 1;
	            }
	        }
	        return 0;
	    }
		
		
//Mostra uma dica
void dica1(int tiro1[2], int navios1[][2], int tentativa1)
{
        int linha=0,
            coluna=0,
            fila;

        //conta quantos navios há na linha tiro[0]
        for(fila=0 ; fila < 3 ; fila++){
            if(navios1[fila][0]==tiro1[0])
                linha++;
            if(navios1[fila][1]==tiro1[1])
                coluna++;
        }

        printf("\nDica %d para o Jogador 1: \nlinha %d -> %d navios\ncoluna %d -> %d navios\n\n\n",tentativa1,tiro1[0]+1,linha,tiro1[1]+1,coluna);
}


void dica2 (int tiro2[2], int navios2[][2], int tentativa2)
{
        int linha=0,
            coluna=0,
            fila;

        //conta quantos navios há na linha tiro[0]
        for(fila=0 ; fila < 3 ; fila++){
            if(navios2[fila][0]==tiro2[0])
                linha++;
            if(navios2[fila][1]==tiro2[1])
                coluna++;
        }

        printf("\nDica %d para o Jogador 2: \nlinha %d -> %d navios\ncoluna %d -> %d navios\n\n\n",tentativa2,tiro2[0]+1,linha,tiro2[1]+1,coluna);
}


void alteraTabuleiro1(int tiro1[2], int navios1[][2], int tabuleiro1[][5]){
        if(acertou1(tiro1,navios1))
            tabuleiro1[tiro1[0]][tiro1[1]]=1;
        else
            tabuleiro1[tiro1[0]][tiro1[1]]=0;
    }

void alteraTabuleiro2(int tiro2[2], int navios2[][2], int tabuleiro2[][5]){
	        if(acertou2(tiro2,navios2))
	            tabuleiro2[tiro2[0]][tiro2[1]]=1;
	        else
	            tabuleiro2[tiro2[0]][tiro2[1]]=0;
}
		
int main() {

        int tabuleiro1[5][5];
        int navios1[3][2];
        int tiro1[2];
        int tabuleiro2[5][5];
        int navios2[3][2];
        int tiro2[2];
        int tentativas1=0,
            acertos1=0,
			tentativas2=0,
            acertos2=0;

        mensagemInicial();
        inicializaTabuleiro1(tabuleiro1);
        iniciaNavios1(navios1);
        inicializaTabuleiro2(tabuleiro2);
        iniciaNavios2(navios2);
        printf("\n");


        do{
            mostraTabuleiro1(tabuleiro1);
            darTiro1(tiro1);
            tentativas1++;

            if(acertou1(tiro1,navios1)){
                dica1(tiro1,navios1,tentativas1);
                acertos1++;
            }
            else
                dica1(tiro1,navios1,tentativas1);

            alteraTabuleiro1(tiro1,navios1,tabuleiro1);
            mostraTabuleiro2(tabuleiro2);
            darTiro2(tiro2);
            tentativas2++;

            if(acertou2(tiro2,navios2)){
                dica2(tiro2,navios2,tentativas2);
                acertos2++;
            }
            else
                dica2(tiro2,navios2,tentativas2);

            alteraTabuleiro2(tiro2,navios2,tabuleiro2);
			

        }while((acertos1!=3) && (acertos2!=3));

        
		if (acertos1==3) {
			
			printf("\n\n\nJogo terminado. Jogador 1 acertou os 3 navios em %d tentativas", tentativas1);
	        mostraTabuleiro1(tabuleiro1);
			
			
		}
		
		if (acertos2==3) {
			
			printf("\n\n\nJogo terminado. Jogador 2 acertou os 3 navios em %d tentativas", tentativas2);
	        mostraTabuleiro2(tabuleiro2);
			
			
		}
		

    return 0;
   }