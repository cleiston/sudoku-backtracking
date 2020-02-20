#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define n 9
#define true 1
#define false 0
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define TEMPO 5000

int iter = 0; 

void imprime(int sudoku[][9]){
	printf("\n---------------------");
	for(int i=0; i<n; i++){
		printf("\n| ");
		for(int j=0; j<n; j++){
			printf("%d ", sudoku[i][j]);
		}
		printf("|");
	}
	printf("\n---------------------\n\n");
}

int encontraPosLivre(int sudoku[][9], int *x, int *y){
	for(*x=0; *x<n; *x=*x+1)
		for(*y=0; *y<n; *y=*y+1)
			if(sudoku[*x][*y] == 0) return true;
	return false;
}

int posLegal(int sudoku[][9], int x, int y, int k){
	int startX = x - x%3;
	int startY = y - y%3;
	int i, j;
	//verifica vizinhanca
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			if(sudoku[i+startX][j+startY] == k) return false;
		}
	}
	// verifica coluna
	for(i=0; i<n; i++)
		if(sudoku[i][y] == k) return false;

	// verifica linha
	for(i=0; i<n; i++)
		if(sudoku[x][i] == k) return false;

	return true;
}

void imprimirTabuleiro(int sudoku[][9])
{
    printf( ANSI_COLOR_CYAN "\n - SODOKU BACKTRACKING - \n\n");
    
    
    printf( ANSI_COLOR_BLUE "- - - - - - - - - - - - - \n");
    
    for(int lin = 0; lin < 9; lin++) {
        printf(ANSI_COLOR_CYAN "| ");
        for(int col=0; col<9; col++){
            
            if(sudoku[lin][col] == 0 ) printf("  ");
            else printf(ANSI_COLOR_GREEN "%d ",  sudoku[lin][col]);
            
            if ((col+1)%3 == 0) printf( ANSI_COLOR_CYAN "| ");
        }
        if ((lin+1)%3 == 0) printf( ANSI_COLOR_CYAN "\n- - - - - - - - - - - - - ");
        
        printf("\n");
        
    }
}

int resolve(int sudoku[][9]){
	int x, y, tentativa;
	if(!encontraPosLivre(sudoku, &x, &y)) return true; // puzzle resolvido
	for(tentativa=1; tentativa<=9; tentativa++){
		if(posLegal(sudoku, x, y, tentativa)){
			sudoku[x][y] = tentativa;

			usleep(TEMPO); // pausa a execucao por TEMPO microsegundos
		    system("clear");
		    printf("%d\n", iter++);
		    imprimirTabuleiro(sudoku);

			if(resolve(sudoku))
				return true;
			sudoku[x][y] = 0; // remove tentativa realizada
		}
	}
	return false;
}


int main(){
	int sudoku[][9] = 
		{ {3, 0, 6, 5, 0, 8, 4, 0, 0},
		  {5, 2, 0, 0, 0, 0, 0, 0, 0},
		  {0, 8, 7, 0, 0, 0, 0, 3, 1},
		  {0, 0, 3, 0, 1, 0, 0, 8, 0},
		  {9, 0, 0, 8, 6, 3, 0, 0, 5},
		  {0, 5, 0, 0, 9, 0, 6, 0, 0},
		  {1, 3, 0, 0, 0, 0, 2, 5, 0},
		  {0, 0, 0, 0, 0, 0, 0, 7, 4},
		  {0, 0, 5, 2, 0, 6, 3, 0, 0} };

	if (resolve(sudoku) == true)
    {
		system("clear");
		printf("%d\n", iter++);
		imprimirTabuleiro(sudoku);
    }
    else
		printf("Não existe solução");

}
