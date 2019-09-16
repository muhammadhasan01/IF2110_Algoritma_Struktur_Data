#include <stdio.h>
#include <stdlib.h>
#include "arraydin.h"
#include "boolean.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty(TabInt *T, int maxel)
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel + 1 */
{
  TI(*T) = (int*) malloc((maxel + 1) * sizeof(int));
  MaxEl(*T) = maxel;
  Neff(*T) = 0;
}
void Dealokasi(TabInt *T)
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */
{
  free(TI(*T));
  MaxEl(*T) = Neff(*T) = 0;
}
/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt(TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{
  return Neff(T);
}
/* *** Daya tampung container *** */
int MaxElement(TabInt T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
  return MaxEl(T);
}
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx(TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
  return IdxMin;
}
IdxType GetLastIdx(TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
  return NbElmt(T);
}
/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
  return (IdxMin <= i && i <= MaxElement(T));
}
boolean IsIdxEff(TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
  return (GetFirstIdx(T) <= i && i <= GetLastIdx(T));
}
/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty(TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
  return (Neff(T) == 0);
}
/* *** Test tabel penuh *** */
boolean IsFull(TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
  return (Neff(T) == MaxElement(T));
}
/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi(TabInt *T)
/* I.S. T sembarang dan sudah dialokasikan sebelumnya */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxElement(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxElement(T); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
{
  int n;
  do {
    scanf("%d", &n);
  } while (n < 0 || n > MaxElement(*T));
  for (int i = IdxMin; i <= IdxMin + n - 1; i++) {
    scanf("%d", &Elmt(*T, i));
  }
  Neff(*T) = n;
}
void TulisIsiTab(TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
{
  printf("[");
    for (int i = IdxMin; i <= Neff(T); i++) {
      printf("%d", Elmt(T, i));
      if (i < Neff(T)) printf(",");
    }
  printf("]");
}
/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusMinusTab(TabInt T1, TabInt T2, boolean plus)
/* Prekondisi : T1 dan T2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
{
  int kali = (plus ? 1 : - 1);
  TabInt hasil;
  MakeEmpty(&hasil, MaxEl(T1));
  Neff(hasil) = Neff(T1);
  for (int i = IdxMin; i <= Neff(hasil); i++) {
    Elmt(hasil, i) = Elmt(T1, i) + Elmt(T2, i) * kali;
  }
  return hasil;
}
/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ(TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika Neff T1 = T2 dan semua elemennya sama */
{
  if (Neff(T1) != Neff(T2)) return false;
  for (int i = IdxMin; i <= Neff(T1); i++) {
    if (Elmt(T1, i) != Elmt(T2, i)) return false;
  }
  return true;
}
/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1(TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
{
  if (Neff(T) == 0) return IdxUndef;
  for (int i = IdxMin; i <= Neff(T); i++) {
    if (Elmt(T, i) == X) return i;
  }
  return IdxUndef;
}
boolean SearchB(TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */
{
  for (int i = IdxMin; i <= Neff(T); i++) {
    if (Elmt(T, i) == X) return true;
  }
  return false;
}
/* ********** NILAI EKSTREM ********** */
void MaxMin(TabInt T, ElType *Max, ElType *Min)
/* I.S. Tabel T tidak kosong */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
{
  int maks, mins;
  maks = mins = Elmt(T, IdxMin);
  for (int i = IdxMin; i <= Neff(T); i++) {
    if (Elmt(T, i) > maks) maks = Elmt(T, i);
    if (Elmt(T, i) < mins) mins = Elmt(T, i);
  }
  *Max = maks;
  *Min = mins;
}
/* ********** OPERASI LAIN ********** */
void CopyTab(TabInt Tin, TabInt *Tout)
/* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (identik, Neff dan MaxEl sama) */
/* Proses : Menyalin isi Tin ke Tout */
{ 
  MakeEmpty(Tout, MaxEl(Tin));
  Neff(*Tout) = Neff(Tin);
  for (int i = IdxMin; i <= Neff(Tin); i++) {
    Elmt(*Tout, i) = Elmt(Tin, i);
  }
}
ElType SumTab(TabInt T)
/* Menghasilkan hasil penjumlahan semua elemen T */
/* Jika T kosong menghasilkan 0 */
{
  ElType sum = 0;
  for (int i = IdxMin; i <= Neff(T); i++) {
    sum += Elmt(T, i);
  }
  return sum;
}
int CountX(TabInt T, ElType X)
/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */
{
  int ret = 0;
  for (int i = IdxMin; i <= Neff(T); i++) {
    if (Elmt(T, i) == X) ret++;
  }
  return ret;
}
boolean IsAllGenap(TabInt T)
/* Menghailkan true jika semua elemen T genap. T boleh kosong */
{
  if (IsEmpty(T)) return false;
  for (int i = IdxMin; i <= Neff(T); i++) {
    if (Elmt(T, i) % 2 == 1) return false;
  }
  return true;
}
/* ********** SORTING ********** */
void Sort(TabInt *T, boolean asc)
/* I.S. T boleh kosong */
/* F.S. Jika asc = true, T terurut membesar */
/*      Jika asc = false, T terurut mengecil */
/* Proses : Mengurutkan T dengan salah satu algoritma sorting,
   algoritma bebas */
{
  int n = Neff(*T);
  for (int i = IdxMin; i <= n; i++) {
    for (int j = IdxMin; j <= n - 1; j++) {
      if ((!asc && TI(*T)[j] < TI(*T)[j + 1]) || (asc && TI(*T)[j] > TI(*T)[j + 1])) {
        ElType temp = TI(*T)[j];
        TI(*T)[j] = TI(*T)[j + 1];
        TI(*T)[j + 1] = temp;
      }
    }
  }
}
/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl(TabInt *T, ElType X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
  Elmt(*T, ++Neff(*T)) = X;
}
/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl(TabInt *T, ElType *X)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{
  *X = Elmt(*T, Neff(*T)--);
}
/* ********* MENGUBAH UKURAN ARRAY ********* */
void GrowTab(TabInt *T, int num)
/* Proses : Menambahkan max element sebanyak num */
/* I.S. Tabel sudah terdefinisi */
/* F.S. Ukuran tabel bertambah sebanyak num */
{
  MaxEl(*T) += num;
  TI(*T) = (int*) malloc((MaxEl(*T) + 1) * sizeof(int));
}

void ShrinkTab(TabInt *T, int num)
/* Proses : Mengurangi max element sebanyak num */
/* I.S. Tabel sudah terdefinisi, ukuran MaxEl > num, dan Neff < MaxEl - num. */
/* F.S. Ukuran tabel berkurang sebanyak num. */
{
  MaxEl(*T) -= num;
  TI(*T) = (int*) malloc((MaxEl(*T) + 1) * sizeof(int));
}
void CompactTab(TabInt *T)
/* Proses : Mengurangi max element sehingga Neff = MaxEl */
/* I.S. Tabel tidak kosong */
/* F.S. Ukuran MaxEl = Neff */
{
  MaxEl(*T) = Neff(*T);
  TI(*T) = (int*) malloc((MaxEl(*T) + 1) * sizeof(int));
}