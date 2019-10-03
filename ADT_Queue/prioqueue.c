/* MUHAMMAD HASAN / 13518012 */
/* 3 Oktober 2019 */
/* Implementasi prioqueue.c */


#include <stdio.h>
#include <stdlib.h>
#include "prioqueue.h"

/* ********* Prototype ********* */
boolean IsEmpty (Queue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
	return (Head(Q) == Nil && Tail(Q) == Nil);
}
boolean IsFull (Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
	if (Head(Q) == 1) {
		return (Tail(Q) == MaxEl(Q));
	} else {
		return (Head(Q) - Tail(Q) == 1);
	}
}
int NBElmt (Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
	if (IsEmpty(Q)) return 0;
	int ret = Tail(Q) - Head(Q) + 1;
	if (ret <= 0) ret += MaxEl(Q);
	return ret;
}
/* *** Kreator *** */
void CreateEmpty (Queue * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
	(*Q).T = (infotype *) malloc ((Max + 1) * sizeof(infotype));
    if ((*Q).T != NULL) {
        MaxEl(*Q) = Max;
        Head(*Q) = Tail(*Q) = Nil;
    } else {
        MaxEl(*Q) = 0;
    }
}
/* *** Destruktor *** */
void DeAlokasi(Queue * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
	free((*Q).T);
    MaxEl(*Q) = 0;
}
/* *** Primitif Add/Delete *** */
void Add (Queue * Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
{
    if (IsEmpty(*Q)) {
        Head(*Q) = 1;
        Tail(*Q) = 1;
        Prio(InfoTail(*Q)) = Prio(X);
        Info(InfoTail(*Q)) = Info(X);
    } else {

    	if (Prio(X) <= Prio(InfoTail(*Q))) {
    		Tail(*Q)++;
	        if (Tail(*Q) > MaxEl(*Q)) Tail(*Q) -= MaxEl(*Q);
        	Prio(InfoTail(*Q)) = Prio(X);
        	Info(InfoTail(*Q)) = Info(X);
	        return;
    	}

        int i = Head(*Q);
        while (1) {
        	if (i > MaxEl(*Q)) i -= MaxEl(*Q);
        	if (Prio(Elmt(*Q, i)) < Prio(X)) {
        		break;
        	}
        	if (i == Tail(*Q)) break;
        	i++;
        }
        Tail(*Q)++;
        if (Tail(*Q) > MaxEl(*Q)) Tail(*Q) -= MaxEl(*Q);
        int j = Tail(*Q);
        int g = i + 1;
        if (g > MaxEl(*Q)) g -= MaxEl(*Q);
        while (1) {
        	if (j == 0) j = MaxEl(*Q);
        	int bf = j - 1;
        	if (bf == 0) bf = MaxEl(*Q);
        	Prio(Elmt(*Q, j)) = Prio(Elmt(*Q, bf));
        	Info(Elmt(*Q, j)) = Info(Elmt(*Q, bf));
        	if (j == g) break;
        	j--;
        }
        Prio(Elmt(*Q, i)) = Prio(X);
        Info(Elmt(*Q, i)) = Info(X);
    }
}
void Del (Queue * Q, infotype * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
{
    *X = InfoHead(*Q);
    if (Head(*Q) == Tail(*Q)) {
        Head(*Q) = Tail(*Q) = Nil;
    } else {
        Head(*Q)++;
    }
}
/* Operasi Tambahan */
void PrintQueue (Queue Q)
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/
{
	if (IsEmpty(Q)) {
		printf("#\n");
		return;
	}
	int i = Head(Q);
	while(1) {
		if (i > MaxEl(Q)) i -= MaxEl(Q);
		printf("%d %d\n", Prio(Elmt(Q, i)), Info(Elmt(Q, i)));
		if (i == Tail(Q)) break;
		i++;
	}
	printf("#\n");
}
