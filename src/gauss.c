#include "gauss.h"

#define MIN(a, b) ((a) < (b) ? (a) : (b))

//wartosc bezwzgledna z liczby
double abs(double a){
	return a >= 0 ? a : -a;
}


// zwraca index rzedu z najwieksza wartoscia bezwgledna liczby w danej kolumnie pod iteratorem
int get_biggest_absolute_value_row(Matrix *A,int iter){
	double max = A -> data[iter][iter];
	int max_value_row_index = iter;
	for (int i = iter; i < A -> r; i++){
		double val = abs(A -> data[i][iter]); 
		if ( val > max ){
			max_value_row_index = i;
			max = val;
		} 
	}
	return max_value_row_index;
}

void replace_rows(Matrix *A, int row1, int row2){
	
}

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
	int operations = MIN(mat -> r, mat -> c); 

	for (int iter = 0; iter < operations; iter++){
		// Zamienia rzędy w zależności od największej wartości bezwzglednej liczby w kolumnie
		int max_r = get_biggest_absolute_value_row(mat, iter);
		if ( max_r != iter){
			replace_rows(mat, iter, max_r);
		}

	}


	return 0;
}

