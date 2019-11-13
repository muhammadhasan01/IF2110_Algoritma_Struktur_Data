/* Nama			: Muhammad Hasan */
/* NIM			: 13518012 */
/* Deskripsi	: delNFromEnd */
#include <stdio.h>
#include <stdlib.h>
#include "listrek.h"

List delNFromEnd(List L, int n)
/* L terdefinisi, tidak mungkin kosong. */
/* Elemen ke-n L dari belakang akan dihapus dan didealokasi,
   lalu mengembalikan head dari list
   misal L = [1, 2, 3, 4, 5] dan n = 2
         L akan menjadi [1, 2, 3, 5] */
{
	address k[100];
	int i = 0;
	while (L != Nil) {
		k[++i] = L;
		L = Next(L);
	}
	k[++i] = Nil;
	if (i - 1 == n) {
		Dealokasi(k[1]);
		return k[2];
	} else {
		SetNext(k[i - n - 1], k[i - n + 1]);
		Dealokasi(k[i - n]);
		return k[1];
	}
}
