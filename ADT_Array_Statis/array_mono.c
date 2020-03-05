// Nama/NIM		: Muhammad Hasan/13518012
// Tanggal 		: 5 September 2019
// Deskripsi		: Menentukan Monotiknya suatu array

#include <stdio.h>
#include "array.h"

int main() {
	TabInt T;
	BacaIsi(&T);
	boolean ok;
	ok = true;
	for (int i = IdxMin; i <= Neff(T) - 1; i++) {
		if (Elmt(T, i) != Elmt(T, i + 1)) {
			ok = false;
			break;
		}
	}
	if (ok) {
		printf("Array monotonik statik\n");
		return 0;
	}
	ok = true;
	for (int i = IdxMin; i <= Neff(T) - 1; i++) {
		if (Elmt(T, i) > Elmt(T, i + 1)) {
			ok = false;
			break;
		}
	}
	if (ok) {
		printf("Array monotonik tidak mengecil\n");
		return 0;
	}
	ok = true;
	for (int i = IdxMin; i <= Neff(T) - 1; i++) {
		if (Elmt(T, i) < Elmt(T, i + 1)) {
			ok = false;
			break;
		}
	}
	if (ok) {
		printf("Array monotonik tidak membesar\n");
		return 0;
	}
	
	printf("Array tidak monotonik\n");

	return 0;
}


