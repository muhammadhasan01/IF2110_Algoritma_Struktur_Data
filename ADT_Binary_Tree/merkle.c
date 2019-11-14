/* NAMA 		: Muhammad Hasan */
/* NIM			: 13518012 */
/* DEKSRIPSI	: merkle.c */
#include <stdio.h>
#include "math.h"
#include "bintree.h"
#include "listrek.h"

int n;
int a[(1 << 21)];

BinTree dapatTree(int s, int e) {
	if (s == e) {
		return Tree(a[s], Nil, Nil);
	} else {
		int mid = (s + e) / 2;
		BinTree L = dapatTree(s, mid);
		BinTree R = dapatTree(mid + 1, e);
		return Tree(Akar(L) + Akar(R), L, R);
	}
}

int main () {

	scanf("%d", &n);
	int cnt = 0;
	for (int i = 21; i >= 0; i--) {
		int k = (n & (1 << i));
		if (k) {
			cnt++;
		}
	}
	if (cnt != 1) {
		printf("Jumlah masukan tidak sesuai\n");
	} else {
		for (int i = 1; i <= n; i++) {
			scanf("%d", a + i);
		}
		BinTree P = dapatTree(1, n);
		PrintTree(P, 2);
	}

	return 0;
}
