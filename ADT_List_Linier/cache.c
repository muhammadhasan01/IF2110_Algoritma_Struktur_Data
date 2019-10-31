/* NAMA/NIM		: MUHAMMAD HASAN/13518012 */
/* TANGGAL		: 24 / 10 / 2019 */
/* DESKRIPSI	: Implementasi Cache.c */
#include <stdio.h>
#include "listlinier.h"

int n, q;
List l;

int main() {
	
	scanf("%d %d", &n, &q);
	CreateEmpty(&l);
	for (int i = n; i >= 1; i--) {
		InsVFirst(&l, i);
	}
	while (q--) {
		int x;
		scanf("%d", &x);
		address cur = Search(l, x);
		if (cur == Nil) {
			address temp;
			DelLast(&l, &temp);
			InsVFirst(&l, x);
			printf("miss ");
			PrintInfo(l);
			printf("\n");
		} else {
			if (cur != First(l)) {
				address temp = First(l);
				while (Next(temp) != cur) {
					temp = Next(temp);
				}
				Next(temp) = Next(cur);
				Next(cur) = First(l);
				First(l) = cur;
			}
			printf("hit ");
			PrintInfo(l);
			printf("\n");
		}
	}

	return 0;
}