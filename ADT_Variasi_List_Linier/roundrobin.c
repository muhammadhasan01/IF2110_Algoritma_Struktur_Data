/* NAMA			: MUHAMMAD HASAN */
/* NIM			: 13518012 */
/* Deskripsi	: Simulasi round robin */

#include <stdio.h>
#include "listsirkuler.h"

List L;

void DeleteRR (List *L, infotype TQ)
/* Jika L tidak kosong, "menghapus" elemen terakhir list L, misal last, sesuai aturan round robin, yaitu:
- jika Info(last)>TQ, maka last "diantrikan" kembali sebagai first elemen dengan Info(last)=Info(last)-TQ
- jika Info(last)<=TQ, maka DeleteLast(L,X) dan menampilkan X ke layar */
/* Jika L kosong, cetak "List kosong" */
/* I.S. TQ terdefinisi sebagai nilai time slice pemrosesan.
L terdefinisi, mungkin kosong. */
/* F.S. Elemen terakhir L diproses sesuai aturan round-robin.
L mungkin menjadi kosong. */
{
    if (IsEmpty(*L)) {
        printf("List kosong\n");
        return;
    }
    address P = First(*L);
    while (Next(P) != First(*L)) {
        P = Next(P);
    }
    if (Info(P) > TQ) {
        printf("%d\n", TQ);
        InsVFirst(L, Info(P) - TQ);
        DelLast(L, &P);
    } else {
        printf("%d\n", Info(P));
        DelLast(L, &P);
    }
}

float Average (List L)
/* Menghasilkan nilai rata-rata elemen L. L tidak kosong. */
{
    float ret = 0, cnt = 0;
    address P = First(L);
    while (Next(P) != First(L)) {
        ret += Info(P); cnt++;
        P = Next(P);
    }
    ret += Info(P); cnt++;
    return ret / cnt;
}

int main() {
	
	int q; char tx = 'A';
	do {
		scanf("%d", &q);
	} while (q <= 0);
	int ok = q;
	while (1) {
		int dpt = q;
		scanf("%s", &tx);
		if (tx == 'A') {
			scanf("%d", &dpt);
			if (dpt > 0) InsVFirst(&L, dpt);
		} else if (tx == 'D') {
			DeleteRR(&L, ok);
		} else if (tx == 'F') {
			break;
		} else {
			printf("Kode salah\n");
		}
	}

	if (IsEmpty(L)) {
		printf("Proses selesai\n");
	} else {
		printf("%.2f\n", Average(L));
	}

	return 0;
}