// Muhammad Hasan - 13518012
// 25 / 09 / 2019
// Program Konvolusi Matriks
#include <stdio.h>
#include "matriks.h"

int n, m, k;
MATRIKS A, B, C;

int main() {

	scanf("%d %d", &n, &m);
	MakeMATRIKS(n, m, &A);
	MakeMATRIKS(n, m, &C);
	BacaMATRIKS(&A, n, m);
	scanf("%d", &k);
	MakeMATRIKS(k, k, &B);
	BacaMATRIKS(&B, k, k);
	int mid = (k + 1) / 2;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			ElType cur = 0;
			int gx = mid - i;
			int gy = mid - j;
			for (int i1 = 1; i1 <= n; i1++) {
				for (int j1 = 1; j1 <= m; j1++) {
					int cx = i1 + gx;
					int cy = j1 + gy;
					if (cx < 1 || cx > k) continue;
					if (cy < 1 || cy > k) continue;
					cur += Elmt(A, i1, j1) * Elmt(B, cx, cy);
				}
			}
			Elmt(C, i, j) = cur;
		}
	}
	TulisMATRIKS(C);

	return 0;
}
