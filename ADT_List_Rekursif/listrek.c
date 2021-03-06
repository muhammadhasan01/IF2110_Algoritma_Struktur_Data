#include <stdio.h>
#include <stdlib.h>
#include "listrek.h"

/* Muhammad Hasan - 13518012 */

/* *** Manajemen Memori *** */
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P,
  maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    ElmtList *P = (ElmtList *) malloc(sizeof(ElmtList));
    if (P != Nil) {
        Info(P) = X;
        Next(P) = Nil;
        return P;
    }
    return Nil;
}
void Dealokasi (address P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(P);
}
/* *** Primitif-primitif yang harus direalisasikan *** */

/* Pemeriksaan Kondisi List */
int IsEmpty(List L)
/* Mengirimkan 1 jika L kosong dan 0 jika L tidak kosong */
{
    return (L == Nil ? 1 : 0);
}
int IsOneElmt(List L)
/* Mengirimkan 1 jika L berisi 1 elemen dan 0 jika > 1 elemen atau kosong */
{
    if (!IsEmpty(L)) {
        return IsEmpty(Next(L));
    } else {
        return 0;
    }
}
/* *** Selektor *** */
infotype FirstElmt (List L)
/* Mengirimkan elemen pertama sebuah list L yang tidak kosong */
{
    return Info(L);
}
List Tail(List L)
/* Mengirimkan list L tanpa elemen pertamanya, mungkin menjadi list kosong */
{
    return Next(L);
}
/* *** Konstruktor *** */
List Konso(infotype e, List L)
/* Mengirimkan list L dengan tambahan e sebagai elemen pertamanya.
e dialokasi terlebih dahulu. Jika alokasi gagal, mengirimkan L. */
{
    address P = Alokasi(e);
    if (P == Nil) return L;
    Next(P) = L;
    return P;
}
List KonsB(List L, infotype e)
/* Mengirimkan list L dengan tambahan e sebagai elemen pertamanya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan L */
{
    address P = Alokasi(e);
    if (IsEmpty(L)) return P;
    Next(L) = KonsB(Tail(L), e);
    return L;
}
/* *** Operasi Lain *** */
List Copy (List L)
/* Mengirimkan salinan list L (menjadi list baru) */
/* Jika ada alokasi gagal, mengirimkan L */
{
    if (IsEmpty(L)) return Nil;
    return Konso(FirstElmt(L), Copy(Tail(L)));
}
void MCopy (List Lin, List *Lout)
/* I.S. Lin terdefinisi */
/* F.S. Lout berisi salinan dari Lin */
/* Proses : menyalin Lin ke Lout */
{
    List temp;
    if (IsEmpty(Lin)) {
        *Lout = Nil;
    } else {
        MCopy(Tail(Lin), &temp);
        *Lout = Konso(FirstElmt(Lin), temp);
    }
}
List Concat (List L1, List L2)
/* Mengirimkan salinan hasil konkatenasi list L1 dan L2 (menjadi list baru) */
/* Jika ada alokasi gagal, menghasilkan Nil */
{
    if (IsEmpty(L1)) return Copy(L2);
    return Konso(FirstElmt(L1), Concat(Tail(L1), L2));
}
void MConcat (List L1, List L2, List *LHsl)
/* I.S. L1, L2 terdefinisi */
/* F.S. LHsl adalah hasil melakukan konkatenasi L1 dan L2 dengan cara "disalin" */
/* Proses : Menghasilkan salinan hasil konkatenasi list L1 dan L2 */
{
    List temp;
    if (IsEmpty(L1)) {
        *LHsl = Copy(L2);
    } else {
        MConcat(Tail(L1), L2, &temp);
        *LHsl = Konso(FirstElmt(L1), temp);
    }
}
void PrintList (List L)
/* I.S. L terdefinisi. */
/* F.S. Setiap elemen list dicetak. */
{
    if (IsEmpty(L)) return;
    printf("%d\n", Info(L));
    PrintList(Tail(L));
}
int NbElmtList (List L)
/* Mengirimkan banyaknya elemen list L, Nol jika L kosong */
{
    if (IsEmpty(L)) return 0;
    return 1 + NbElmtList(Tail(L));
}
boolean Search (List L, infotype X)
/* Mengirim true jika X adalah anggota list, false jika tidak */
{
    if (IsEmpty(L)) return false;
    if (Info(L) == X) return true;
    return Search(Tail(L), X);
}

/*** Pencarian nilai ekstrim ***/
/* Prekondisi untuk Max/Min/Sum/Average : List tidak kosong */
infotype MaxList (List L)
/* Mengirimkan nilai info(P) yang maksimum */
{
    infotype k = Info(L);
    while (L != Nil) {
        if (Info(L) > k) k = Info(L);
        L = Next(L);
    }
    return k;
}
infotype MinList (List L)
/* Mengirimkan nilai info(P) yang minimum */
{
    infotype k = Info(L);
    while (L != Nil) {
        if (Info(L) < k) k = Info(L);
        L = Next(L);
    }
    return k;
}
infotype SumList (List L)
/* Mengirimkan total jumlah elemen List L */
{
    infotype sum = 0;
    while (L != Nil) {
        sum += Info(L);
        L = Next(L);
    }
    return sum;
}
float AverageList (List L)
/* Mengirimkan nilai rata-rata elemen list L */
{
    float sum = 0, cnt = 0;
    while (L != Nil) {
        sum += (float) Info(L);
        ++cnt;
        L = Next(L);
    }
    if (cnt == 0) cnt = 1;
    return sum / cnt;
}
/*** Operasi-Operasi Lain ***/
List InverseList (List L)
/* Mengirimkan list baru, hasil invers dari L dengan menyalin semua elemen list.
Semua elemen list baru harus dialokasi */
/* Jika alokasi gagal, hasilnya list kosong */
{
    if (IsEmpty(L)) return Nil;
    return KonsB(InverseList(Tail(L)), Info(L));
}
void SplitPosNeg (List L, List *L1, List *L2)
/* I.S. L mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 */ 
/* L1 berisi semua elemen L yang positif atau 0, sedangkan L2 berisi
semua elemen L yang negatif; semua dengan urutan yang sama seperti di L */
/* L tidak berubah: Semua elemen L1 dan L2 harus dialokasi */
/* Jika L kosong, maka L1 dan L2 kosong */
{
    while (L != Nil) {
        infotype x = Info(L);
        if (x >= 0) {
            *L1 = KonsB(*L1, x);
        } else {
            *L2 = KonsB(*L2, x);
        }
        L = Next(L);
    }
}
void SplitOnX (List L, infotype X, List *L1, List *L2)
/* I.S. L dan X terdefinisi, L1 dan L2 sembarang. */
/* F.S. L1 berisi semua elemen L yang lebih kecil dari X, dengan urutan
kemunculan yang sama, L2 berisi semua elemen L yang tidak masuk ke
L1, dengan urutan kemunculan yang sama. */
{
    while (L != Nil) {
        infotype x = Info(L);
        if (x < X) {
            *L1 = KonsB(*L1, x);
        } else {
            *L2 = KonsB(*L2, x);
        }
        L = Next(L);
    }
}
int ListCompare (List L1, List L2)
/* Menghasilkan: -1 jika L1 < L2, 0 jika L1 = L2, dan 1 jika L1 > L2 */
/* Jika L[i] adalah elemen L pada urutan ke-i dan |L| adalah panjang L: */
/* L1 = L2: |L1| = |L2| dan untuk semua i, L1[i] = L2[i] */
/* L1 < L2: Jika i adalah urutan elemen yang berbeda yang terkecil
dari L1 dan L2, L1[i]<L2[i] atau: Jika pada semua elemen pada
urutan i yang sama, L1[i]=L2[i], namun |L1|<|L2| */
/* Contoh: [3,5,6,7] < [4,4,5,6]; [1,2,3]<[1,2,3,4] */
/* L1>L2: kebalikan dari L1<L2 */
{
    int k1 = NbElmtList(L1);
    int k2 = NbElmtList(L2);
    if (k1 < k2) return -1;
    if (k1 > k2) return 1;
    while (L1 != Nil) {
        if (Info(L1) > Info(L2)) return 1;
        if (Info(L1) < Info(L2)) return -1;
        L1 = Next(L1);
        L2 = Next(L2);
    }
    return 0;
}
boolean IsAllExist (List L1, List L2)
/* Menghasilkan true jika semua elemen dalam L1 terdapat dalam L2 (tanpa
memperhatikan urutan ataupun banyaknya elemen).
Kedua list mungkin kosong. Jika L1 kosong, maka hasilnya false. */
{
    if (IsEmpty(L1) || IsEmpty(L2)) return false;
    while (L1 != Nil) {
        if (!Search(L2, Info(L1))) return false;
        L1 = Next(L1);
    }
    return true;
}