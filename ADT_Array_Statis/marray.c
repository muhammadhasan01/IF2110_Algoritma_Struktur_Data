// Nama/NIM		: Muhammad Hasan/13518012
// Tanggal 		: 5 September 2019
// Deskripsi	: Menggunakan ADT Array Statis

#include <stdio.h>
#include "array.h"

int main() {
	TabInt T;
	BacaIsi(&T);
	TulisIsiTab(T);
	printf("\n");
	int X;
	scanf("%d", &X);
	int banyakX = 0, idxPertamaKali = -1;
	for (int i = IdxMin; i <= Neff(T); i++) {
		if (Elmt(T, i) == X) {
			banyakX++;
			if (idxPertamaKali == -1) {
				idxPertamaKali = i;
			}
		}
	}
	printf("%d\n", banyakX);
	if (idxPertamaKali == -1) {
		printf("%d tidak ada\n", X);
		return 0;
	} else {
		printf("%d\n", idxPertamaKali);
	}
	InsSortAsc(&T);
	if (X == Elmt(T, Neff(T))) {
		printf("maksimum\n");
	}
	if (X == Elmt(T, 1)) {
		printf("minimum\n");
	}
	if ((Neff(T) & 1) && (X == Elmt(T, (Neff(T) + 1) / 2))) {
		printf("median\n");
	} else if (X == Elmt(T, Neff(T) / 2)) {
		printf("median\n");
	}



	return 0;
}