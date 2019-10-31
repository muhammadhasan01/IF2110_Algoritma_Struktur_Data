/* MUHAMMAD HASAN - 13518012 */
/* listdp.c */
#include <stdio.h>
#include <stdlib.h>
#include "listdp.h"

boolean IsEmpty (List L)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
    return (First(L) == Last(L) && Last(L) == Nil);
}
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
    First(*L) = Last(*L) = Nil;
}
/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
{
    ElmtList *P = (ElmtList *) malloc(sizeof(ElmtList));
    if (P != Nil) {
        Info(P) = X;
        Prev(P) = Nil;
        Next(P) = Nil;
    }
    return P;
}
void Dealokasi (address P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(P);
}
/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
    address P = First(L);
    while (P != Nil) {
        if (Info(P) == X) return P;
        P = Next(P);
    }
    return Nil;
}
/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    address temp = Alokasi(X);
    InsertFirst(L, temp);
}
void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    address temp = Alokasi(X);
    InsertLast(L, temp);
}
/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    address temp;
    DelFirst(L, &temp);
    *X = Info(temp);
}
void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    address temp;
    DelLast(L, &temp);
    *X = Info(temp);
}
/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
    Next(P) = First(*L);
    if (!IsEmpty(*L)) {
        Prev(First(*L)) = P;
    } else /* L kosong */ {
        Last(*L) = P;
    }
    First(*L) = P;
}
void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    /* Algoritma */
    Prev(P) = Last(*L);
    if (!IsEmpty(*L)) {
        Next(Last(*L)) = P;
    } else /* L kosong */ {
        First(*L) = P;
    }
    Last(*L) = P;
}
void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    /* Algoritma */
    if (Next(Prec) != Nil) { /* Prec bukan elemen terakhir */
        Prev(Next(Prec)) = P;
    } else { /* Prec elemen terakhir */
        Last(*L) = P;
    }
    Next(P) = Next(Prec);
    Prev(P) = Prec;
    Next(Prec) = P;
}
void InsertBefore (List *L, address P, address Succ)
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */
{
    if (Succ == First(*L)) {
        InsertFirst(L, P);
    } else {
        InsertAfter(L, P, Prev(Succ));
    }
}
/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    /* Algoritma */
    *P = First(*L);
    if (First(*L) == Last(*L)) { /* L hanya 1 elemen */
        Last(*L) = Nil;
    } else { /* L > 1 elemen */
        Prev(Next(First(*L))) = Nil;
    }
    First(*L) = Next(First(*L));
    Next(*P) = Nil;
    Prev(*P) = Nil;
}
void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
{
    /* Algoritma */
    *P = Last(*L);
    if (First(*L) == Last(*L)) { /* L hanya 1 elemen */
        First(*L) = Nil;
    } else { /* L > 1 elemen */
        Next(Prev(Last(*L))) = Nil;
    }
    Last(*L) = Prev(Last(*L));
    Next(*P) = Nil;
    Prev(*P) = Nil;
}
void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    address cur = Search(*L, X);
    if (cur == Nil) return;
    if (cur == First(*L)) {
        DelFirst(L, &cur);
    } else {
        address temp;
        DelAfter(L, &temp, Prev(cur));
    }
}
void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    /* Algoritma */
    *Pdel = Next(Prec);
    if (Next(Next(Prec))!=Nil) { /* Prec tidak jadi elemen terakhir */
        Prev(Next(*Pdel)) = Prec;
    } else { /* Prec jadi elemen terakhir */
        Last(*L) = Prec;
    }
    Next(Prec) = Next(Next(Prec));
    Next(*Pdel) = Nil;
    Prev(*Pdel) = Nil;
}
void DelBefore (List *L, address *Pdel, address Succ)
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    if (Succ == First(*L)) {
        *Pdel = Nil;
        return;
    }
    if (Prev(Succ) == First(*L)) {
        DelFirst(L, Pdel);
    } else {
        DelAfter(L, Pdel, Prev(Prev(Succ)));
    }
}
/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForward (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    if (IsEmpty(L)) {
        printf("[]");
        return;
    }

    address P = First(L);
    printf("[%d", Info(P));
    while (Next(P) != Nil) {
        printf(",%d", Info(Next(P)));
        P = Next(P);
    }
    printf("]");
}
void PrintBackward (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    if (IsEmpty(L)) {
        printf("[]");
        return;
    }

    address P = Last(L);
    printf("[%d", Info(P));
    while (Prev(P) != Nil) {
        printf(",%d", Info(Prev(P)));
        P = Prev(P);
    }
    printf("]");
}
