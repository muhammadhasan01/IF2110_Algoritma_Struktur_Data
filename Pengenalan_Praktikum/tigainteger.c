/* Muhammad Hasan - 13518012 */

/* Program TigaInteger */

/* Input: 3 integer: A, B, C */

/* Output: Sifat integer dari A, B, C (positif/negatif/nol dan ganjil/genap)

           Nilai maksimum, minimum, dan nilai tengah */

#include <stdio.h>

 

/* PROCEDURE DAN FUNCTION */

void CekInteger (int x);

/* I.S.: x terdefinisi */

/* F.S.: Jika x positif dan genap, maka tertulis di layar: POSITIF-GENAP

         Jika x positif dan ganjil, maka tertulis di layar: POSITIF-GANJIL

         Jika x negatif, maka tertulis di layar: NEGATIF

         Jika x nol, maka tertulis di layar: NOL */

             

int Max (int a, int b, int c);

/* menghasilkan nilai terbesar di antara a, b, c */

 

int Min (int a, int b, int c);

/* menghasilkan nilai terkecil di antara a, b, c */

       

/* PROGRAM UTAMA */

int main () {

       /* KAMUS */

       int A, B, C;

       int nilaitengah;

 

       /* ALGORITMA */

       /* Input */

       scanf("%d", &A);

       scanf("%d", &B);

       scanf("%d", &C);

      

       /* Menuliskan sifat integer */

       CekInteger(A);

       CekInteger(B);

       CekInteger(C);

 

       /* Penulisan maksimum, minimum, dan nilai tengah */

       printf("%d\n", Max(A,B,C));

       printf("%d\n", Min(A,B,C));

       nilaitengah = A + B + C - Max(A,B,C) - Min(A,B,C);

       printf("%d\n", nilaitengah);

      

       return 0;

}

/* Tuliskan realisasi fungsi dan procedure di bawah ini */
int Max (int a, int b, int c) {
	int ret = (a > b ? a : b);
	ret = (ret > c ? ret : c);
	return ret;
}

int Min (int a, int b, int c) {
	int ret = (a > b ? b : a);
	ret = (ret > c ? c : ret);
	return ret;
}

void CekInteger (int x) {
	if (x > 0 && x % 2 == 0) {
		printf("POSITIF-GENAP\n");
	} else if (x > 0 && x % 2 == 1) {
		printf("POSITIF-GANJIL\n");
	} else if (x < 0) {
		printf("NEGATIF\n");
	} else if (x == 0) {
		printf("NOL\n");
	}
}
