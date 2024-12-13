#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
	if (mat->c > mat->r 	||
		b->r != mat->r		||
		x->r != mat->c)
		return 2;

	int i, j;
	for (i = x->r-1; i >= 0; i--) {

		if (mat->data[i][i] == 0)
			return 1;

		x->data[i][0] = b->data[i][0];
		for (j = mat->c-1; j>i; j--){
			x->data[i][0] -= x->data[j][0]*mat->data[i][j];
		}
		x->data[i][0] /= mat->data[i][i];
	}

	return 0;
}


