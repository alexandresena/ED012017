/*Estruturas de Dados - Turma B - Prof. Gustavo Van Erven*/
/*Alunos: Alexandre Sena - 16/0056969 e
  Marcos Paes da Silva  - 14/0153101*/

#include <stdio.h>
#include <stdlib.h>

//Imprime a mensagem inicial
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

    //Chama o ENTER para passar a página
    printf("Digite ENTER para continuar: \n");
    getchar();
}

//inicia o tabuleiro do jogo 1
void iniciaTab1(int tabuleiro1[][5]){
    int lin, col;
        //incrementa a função tabuleiro
        for(lin=0 ; lin < 5 ; lin++ )
            for(col=0 ; col < 5 ; col++ )
                tabuleiro1[lin][col]=-1;
}

//inicia o tabuleiro do jog. 2
void iniciaTab2(int tabuleiro2[][5]){
    int lin, col;
        for(lin=0 ; lin < 5 ; lin++ )
            for(col=0 ; col < 5 ; col++ )
                tabuleiro2[lin][col]=-1;
}


//Printa o tabuleiro
void exibeTab1(int tabuleiro1[][5]){

    int lin, col;
		printf ("\n Jogador 01\n\n");
        printf("\t1 \t2 \t3 \t4 \t5");
        printf("\n");

        for(lin=0 ; lin < 5 ; lin++ ){
            printf("%d",lin+1);
            for(col=0 ; col < 5 ; col++ ){
                if(tabuleiro1[lin][col]==-1){
                    printf(" \t-");
                }
                if(tabuleiro1[lin][col]==0){
                    printf(" \t*");
                }
                if(tabuleiro1[lin][col]==1){
                    printf(" \tX");
                }

            }
            printf("\n\n");
        }

    }
    //Printa do tabuleiro 2
	void mostraTab2(int tabuleiro2[][5]){

	    int lin, col;

			printf ("\n\nJogador 02\n\n");
			//mostra os locais de lin e col
	        printf("\t1 \t2 \t3 \t4 \t5");
	        //Quebra a lin entre lin e col
	        printf("\n");

	        for(lin=0 ; lin < 5 ; lin++ ){
	            printf("%d",lin+1);
	            for(col=0 ; col < 5 ; col++ ){
	                if(tabuleiro2[lin][col]==-1){
	                    printf(" \t-");
	                }
	                if(tabuleiro2[lin][col]==0){
	                    printf(" \t*");
	                }
                    if(tabuleiro2[lin][col]==1){
	                    printf(" \tX");
	                }

	            }
	            printf("\n\n");
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

//Mapea os navios
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
void dartiros1(int tiros1[2]){

        printf("lin: ");
        scanf("%d",&tiros1[0]);
        tiros1[0]--;

        printf("col: ");
        scanf("%d",&tiros1[1]);
        tiros1[1]--;

}

//Função que dá tiro
void dartiros2(int tiros2[2]){
        //Tiros em linhas
        printf("lin: ");
        scanf("%d",&tiros2[0]);
        tiros2[0]--;
        //Tiros em colunas
        printf("col: ");
        scanf("%d",&tiros2[1]);
        tiros2[1]--;

}



// Em caso de acerto  jog. 1 , chama a função.
int acertou1(int tiros1[2], int navios1[][2]){
    int navio;

        for(navio=0 ; navio < 3 ; navio++){
            if( tiros1[0]==navios1[navio][0] && tiros1[1]==navios1[navio][1]){
                printf("Jogador acertou o tiro '%d,%d'\n",tiros1[0]+1,tiros1[1]+1);
                return 1;
            }
        }
        return 0;
    }

// Em caso de acerto  jog. 2 , chama a função.
	int acertou2(int tiros2[2], int navios2[][2]){
	    int navio;

	        for(navio=0 ; navio < 3 ; navio++){
	            if( tiros2[0]==navios2[navio][0] && tiros2[1]==navios2[navio][1]){
	                printf("Jogador acertou o tiro '%d,%d'\n",tiros2[0]+1,tiros2[1]+1);
	                return 1;
	            }
	        }
	        return 0;
	    }


//Mostra uma dica
void dica1(int tiros1[2], int navios1[][2], int tentativa1){
        int lin=0,
            col=0,
            fila;

        //conta quantos navios há na lin tiro[0]
        for(fila=0 ; fila < 3 ; fila++){
            if(navios1[fila][0]==tiros1[0])
                //incrementa linhas
                lin++;
            if(navios1[fila][1]==tiros1[1])
                //incrementa colunas
                col++;
        }

        printf("\nDica %d ao Jogador 1: \nlin %d -> %d navios\ncol %d -> %d navios\n\n\n",tentativa1,tiros1[0]+1,lin,tiros1[1]+1,col);
}


void dica2 (int tiros2[2], int navios2[][2], int tentativa2){
        int lin=0,
            col=0,
            fila;

        //conta quantos navios há na lin tiro[0]
        for(fila=0 ; fila < 3 ; fila++){
            if(navios2[fila][0]==tiros2[0])
                //incrementa linhas
                lin++;
            if(navios2[fila][1]==tiros2[1])
                //incrementa linhas
                col++;
        }

        printf("\nDica %d ao Jogador 2: \nlin %d -> %d navios\ncol %d -> %d navios\n",tentativa2,tiros2[0]+1,lin,tiros2[1]+1,col);
}

//Alterna o tabuleiro por jogador
void alteraTabuleiro1(int tiros1[2], int navios1[][2], int tabuleiro1[][5]){
        if(acertou1(tiros1,navios1))
            tabuleiro1[tiros1[0]][tiros1[1]]=1;
        else
            tabuleiro1[tiros1[0]][tiros1[1]]=0;
    }

void alteraTabuleiro2(int tiros2[2], int navios2[][2], int tabuleiro2[][5]){
	        if(acertou2(tiros2,navios2))
	            tabuleiro2[tiros2[0]][tiros2[1]]=1;
	        else
	            tabuleiro2[tiros2[0]][tiros2[1]]=0;
}

int main() {

        int tabuleiro1[5][5];
        int tabuleiro2[5][5];
        int navios1[3][2];
        int navios2[3][2];
        int tiros1[2];
        int tiros2[2];


        int tentativas1=0, tentativas2=0,acertos1=0, acertos2=0;

        mensagemInicial();
        iniciaTab1(tabuleiro1);
        iniciaNavios1(navios1);
        iniciaTab2(tabuleiro2);
        iniciaNavios2(navios2);
        printf("\n");


        do{
            exibeTab1(tabuleiro1);
            dartiros1(tiros1);
            tentativas1++;

            if(acertou1(tiros1,navios1)){
                dica1(tiros1,navios1,tentativas1);
                acertos1++;
            }
            else
                dica1(tiros1,navios1,tentativas1);

            alteraTabuleiro1(tiros1,navios1,tabuleiro1);
            mostraTab2(tabuleiro2);
            dartiros2(tiros2);
            tentativas2++;

            if(acertou2(tiros2,navios2)){
                dica2(tiros2,navios2,tentativas2);
                acertos2++;
            }
            else
                dica2(tiros2,navios2,tentativas2);

            alteraTabuleiro2(tiros2,navios2,tabuleiro2);


        }while((acertos1!=3) && (acertos2!=3));

        //Se os acertos forem suficientes para terminar o jogo
		if (acertos1==3) {

			printf("\n\nJogo terminado. Jogador 1 acertou os 3 navios em %d tentativas", tentativas1);
	        exibeTab1(tabuleiro1);


		}
		//Se os acertos forem suficientes para terminar o jogo
		if (acertos2==3) {

			printf("\n\n\nJogo terminado. Jogador 2 acertou 3 navios em %d tentativas", tentativas2);
	        mostraTab2(tabuleiro2);

		}


    return 0;
}