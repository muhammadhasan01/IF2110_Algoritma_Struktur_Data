#include <stdio.h>
#include <stdlib.h>
#include "listsirkuler.h"
/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
    return (First(L) == Nil);
}
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. L sembarang             */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
    First(*L) = Nil;
}
/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    ElmtList *P = (ElmtList *) malloc(sizeof(ElmtList));
    if (P != Nil) {
        Info(P) = X;
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
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
    address P = First(L);
    do {
        if (Info(P) == X) return P;
        P = Next(P);
    } while ((P != First(L)));
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
void DelVFirst (List *L, infotype * X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    address temp;
    DelFirst(L, &temp);
    *X = Info(temp);
}
void DelVLast (List *L, infotype * X)
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
    /* Kamus Lokal */
    address last;
    /* Algoritma */
    if (IsEmpty(*L)) {
        Next(P) = P;
    } else /* L tidak kosong */ {
        last = First(*L);
        while (Next(last) != First(*L)) {
            last = Next(last);
        } /* Next(last) = First(L) ==> elemen terakhir */
        Next(P) = First(*L);
        Next(last) = P;
    }
    First(*L) = P;
}
void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    address last;
    /* Algoritma */
    if (IsEmpty(*L)) {
        InsertFirst(L, P);
    } else {
        last = First(*L);
        while (Next(last) != First(*L)) {
                last = Next(last);
        } /* Next(last) = First(L) */
        Next(last) = P;
        Next(P) = First(*L);
    }
}
void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    Next(P) = Next(Prec);
    Next(Prec) = P;
}
/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    /* Kamus Lokal */
    address last;
    /* Algoritma */
    *P = First(*L);
    if (Next(First(*L)) == First(*L)) { /* satu elemen */
        First(*L) = Nil;
    } else {
        last = First(*L);
        while (Next(last) != First(*L)) {
            last = Next(last);
        } /* Next(last) = First(L) */
        First(*L) = Next(First(*L));
        Next(last) = First(*L);
    }
    Next(*P) = Nil;
}
void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
{
    if (First(*L) == Next(First(*L))) {
        *P = First(*L);
        First(*L) = Nil;
    } else {
        address cur = First(*L);
        while (Next(Next(cur)) != First(*L)) {
            cur = Next(cur);
        }
        DelAfter(L, P, cur);
    }
    Next(*P) = Nil;
}
void DelAfter (List *L, address *Pdel, address Prec)/*/
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    if (Next(Prec) == First(*L)) {
        First(*L) = Next(First(*L));
    } else if (Next(First(*L)) == First(*L)) {
        First(*L) = Nil;
    } else {
        *Pdel = Next(Prec);
        Next(Prec) = Next(Next(Prec));
        Next(*Pdel) = Nil;
    }

}
void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    if (IsEmpty(*L)) return;
    address Last = First(*L);
    if (Info(Last) == X) {
        address temp;
        DelFirst(L, &temp);
        return;
    }
    address bf = Nil;
    do {
        if (Info(Last) == X) {
            if (bf == Nil) {
                First(*L) = Nil;
                //Dealokasi(&Last);
            } else if (Next(Last) != First(*L)) {
                Next(bf) = Next(Last);
                //Dealokasi(&Last);
            } else if (Next(Last) == First(*L)) {
                address temp;
                DelLast(L, &temp);
                //Dealokasi(&Last);
            }
            return;
        }
        bf = Last;
        Last = Next(Last);
    } while (Last != First(*L));
}
/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
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
    while (Next(P) != First(L)) {
        printf(",%d", Info(Next(P)));
        P = Next(P);
    }
    printf("]");
}
