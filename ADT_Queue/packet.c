/* MUHAMMAD HASAN / 13518012 */
/* 3 Oktober 2019 */
/* Implementasi packet.c */

#include <stdio.h>
#include "prioqueuechar.h"

int n;

int main() {
	scanf("%d", &n);
	char a[n + 5];
	for (int i = 1; i <= n; i++) {
		a[i] = '#';
	}
	for (int i = 1; i <= n; i++) {
		int pos; char x;
		scanf("%d %c", &pos, &x);
		a[pos] = x;
		int flag = 1;
		for (int j = pos - 1; j >= 1; j--) {
			if (a[j] == '#') {
				flag = 0;
				break;
			}
		}
		if (flag) {
			for (int j = 1; j <= n; j++) {
				if (a[j] == '-') continue;
				if (a[j] == '#') break;
				printf("%d %c\n", i, a[j]);
				a[j] = '-';
			}
		}
	}

	return 0;
}