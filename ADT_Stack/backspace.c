// NAMA       : Muhammad Hasan
// NIM        : 13518012
// Tanggal    : 17/10/2019
// Deskripsi  : Mengimplementasikan backspace.c
#include <stdio.h>
#include "stackt.h"

int main() {
	
	int n, m;
	scanf("%d %d", &n, &m);
	int a[n + 5], b[m + 5];
	int ka = 0, kb = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		if (x == 0) {
			if (ka == 0) continue;
			else ka--;
		} else {
			a[++ka] = x;
		}
	}
	for (int i = 1; i <= m; i++) {
		int x;
		scanf("%d", &x);
		if (x == 0) {
			if (kb == 0) continue;
			else kb--;
		} else {
			b[++kb] = x;
		}
	}
	int same = 1;
	if (ka != kb) {
		same = 0;
	} else {
		for (int i = 1; i <= ka; i++) {
			if (a[i] != b[i]) {
				same = 0;
				break;
			}
		}
	}
	if (same) {
		printf("Sama\n");
	} else {
		printf("Tidak sama\n");
	}

	return 0;
}