// Muhammad Hasan - 13518012
// Tanggal : 27/08/2019
// Program Jumlah Deret - Menghasilkan hasil jumlah dari 1 + 2 + ... + n
// dengan n adalah sebuah bilangan asli dari input

#include<stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", n * (n + 1) / 2);
	return 0;
}
