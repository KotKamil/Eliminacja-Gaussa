#include "gauss.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#define MIN(a, b) ((a) < (b) ? (a) : (b))



// zwraca index rzedu z najwieksza wartoscia bezwgledna liczby w danej kolumnie pod iteratorem
int get_biggest_absolute_value_row(Matrix *A,int iter){
	double max = fabs(A -> data[iter][iter]);
	int max_value_row_index = iter;
	for (int i = iter + 1; i < A -> r; i++){
		double val = fabs(A -> data[i][iter]); 
		if ( val > max ){
			max_value_row_index = i;
			max = val;
		} 
	}
	return max_value_row_index;
}

void replace_rows(Matrix *A, Matrix *b, int row1, int row2){
	double *tmp_p = A -> data[row1];
	A -> data[row1] = A -> data[row2];
	A -> data[row2] = tmp_p;

	double tmp = b -> data[row1][0];
	b -> data[row1][0] = b -> data[row2][0];
	b -> data[row1][0] = tmp;
}

//Zwraca 1 przy dzieleniu przez 0
int set_factor(double *factor, Matrix *mat, int row, int iter){
	if (mat -> data[iter][iter] == 0){
		return 1;
	}
	*factor = (mat -> data[row][iter]) / (mat -> data[iter][iter]);
	return 0;
}

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){

	int operations = MIN(mat -> r, mat -> c); 

	for (int iter = 0; iter < operations - 1; iter++){ // dla ostatniego rzedu nie musismy nic odejmowac
		// Zamienia rzędy w zależności od największej wartości bezwzglednej liczby w kolumnie
		int max_r = get_biggest_absolute_value_row(mat, iter);
		if ( max_r != iter){ replace_rows(mat, b, iter, max_r); }
		double factor = 0;
		for (int row = iter + 1; row < mat -> r; row++){

			if(set_factor(&factor, mat, row, iter)){ return 1; } // ustawia factor i sprawdza czy macierz nie jest osobliwa

			for (int column = iter; column < mat -> c; column++){
				mat -> data[row][column] -= (mat -> data[iter][column]) * factor;
			}
			
			b -> data[row][0] -= (b -> data[iter][0]) * factor;
		}
	}

	return 0;
}

