// Muhammad Hasan - 13518012
// Tanggal : 27/08/2019
// Program Maksimum - Menuliskan Hasil Maksimum dari Tiga Buah Integer yang diinput

#include<stdio.h>

int max(int a, int b) {
	return (a > b ? a : b);
}

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	printf("%d\n", max(a,max(b,c)));
	return 0;
}
