// Nama/NIM   : Muhammad Hasan/13518012
// Tanggal    : 03/09/2019

#include <stdio.h>
#include "array.h"

void MakeEmpty (TabInt * T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
{
    Neff(*T) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{
    return Neff(T);
}
/* *** Daya tampung container *** */
int MaxNbEl (TabInt T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
    return IdxMax;
}
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
    return IdxMin;
}
IdxType GetLastIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
    return Neff(T);
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    return (IdxMin <= i && i <= IdxMax);
}
boolean IsIdxEff (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
    return (IdxMin <= i && i <= Neff(T));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
    return (Neff(T) == 0);
}
/* *** Test tabel penuh *** */
boolean IsFull (TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
    return (Neff(T) == (IdxMax - IdxMin + 1));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi (TabInt * T)
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxNbEl(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxNbEl(T); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
{
    int N;
    do {
        scanf("%d", &N);
    } while (!(0 <= N && N <= MaxNbEl(*T)));

    for (int i = IdxMin, j = 1; j <= N; i++, j++) {
        scanf("%d", &Elmt(*T, i));
    }
    Neff(*T) = N;
}
void BacaIsiTab (TabInt * T)
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca elemen T sampai dimasukkan nilai -9999 */
/* Dibaca elemen satu per satu dan disimpan mulai dari IdxMin */
/* Pembacaan dihentikan jika pengguna memasukkan nilai -9999 */
/* Jika dari pertama dimasukkan nilai -9999 maka terbentuk T kosong */
{
    int t;
    IdxType pos = IdxMin;
    while (true) {
        if (pos > IdxMax) break;
        scanf("%d", &t);
        if (t == -9999) break;
        Elmt(*T, pos++) = t;
    }
    Neff(*T) = pos - 1;
}
void TulisIsi (TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/*      Jika T kosong : Hanya menulis "Tabel kosong" */
/* Contoh: Jika isi Tabel: [1, 20, 30, 50]
   Maka tercetak di layar:
   [1]1
   [2]20
   [3]30
   [4]50
*/
{
    if (Neff(T) == 0) {
        printf("Tabel kosong\n");
    } else {
        for (int i = IdxMin; i <= Neff(T); i++) {
            printf("[%d]%d\n", i, Elmt(T, i));
        }
    }
}
void TulisIsiTab (TabInt T)
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
TabInt PlusTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
{
    TabInt hasil;
    Neff(hasil) = Neff(T1);
    for (int i = IdxMin; i <= Neff(hasil); i++) {
        TI(hasil)[i] = TI(T1)[i] + TI(T2)[i];
    }
    return hasil;
}
TabInt MinusTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
{
    TabInt hasil;
    Neff(hasil) = Neff(T1);
    for (int i = IdxMin; i <= Neff(hasil); i++) {
        TI(hasil)[i] = TI(T1)[i] - TI(T2)[i];
    }
    return hasil;
}
TabInt KaliTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 * T2 dengan definisi setiap elemen dengan indeks yang sama dikalikan */
{
    TabInt hasil;
    Neff(hasil) = Neff(T1);
    for (int i = IdxMin; i <= Neff(hasil); i++) {
        TI(hasil)[i] = TI(T1)[i] * TI(T2)[i];
    }
    return hasil;
}
TabInt KaliKons (TabInt Tin, ElType c)
/* Prekondisi : Tin tidak kosong */
/* Mengirimkan tabel dengan setiap elemen Tin dikalikan c */
{
    TabInt hasil;
    Neff(hasil) = Neff(Tin);
    for (int i = 1; i <= Neff(hasil); i++) {
        TI(hasil)[i] = TI(Tin)[i] * c;
    }
    return hasil;
}
/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ (TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua elemennya sama */
{
    if (Neff(T1) != Neff(T2)) return false;
    for (int i = IdxMin; i <= Neff(T1); i++) {
        if (Elmt(T1, i) != Elmt(T2, i)) return false;
    }
    return true;
}
boolean IsLess (TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 < T2, */
/* yaitu : sesuai dg analogi 'Ali' < Badu'; maka [0, 1] < [2, 3] */
{
    IdxType mins = (Neff(T1) > Neff(T2) ? Neff(T2) : Neff(T1));
    for (int i = IdxMin; i <= mins; i++) {
        if (TI(T1)[i] < TI(T2)[i]) {
            return true;
        } else if (TI(T1)[i] > TI(T2)[i]) {
            return false;
        }
    }
    return (Neff(T1) < Neff(T2));
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1 (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search TANPA boolean */
{
    if (Neff(T) == 0) return IdxUndef;
    for (int i = IdxMin; i <= Neff(T); i++) {
        if (Elmt(T, i) == X) return i;
    }
    return IdxUndef;
}
IdxType Search2 (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search DENGAN boolean Found */
{
    IdxType retIdx;
    boolean found = false;
    for (int i = IdxMin; i <= Neff(T); i++) {
        if (Elmt(T, i) == X) {
            retIdx = i;
            found = true;
            break;
        }
    }
    return (found ? retIdx : IdxUndef);
}
boolean SearchB (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Memakai Skema search DENGAN boolean */
{
    if (Neff(T) == 0) return false;
    for (int i = IdxMin; i <= Neff(T); i++) {
        if (Elmt(T, i) == X) return true;
    }
    return false;
}
boolean SearchSentinel (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* dengan metoda sequential search dengan sentinel */
/* Untuk sentinel, manfaatkan indeks ke-0 dalam definisi array dalam Bahasa C
   yang tidak dipakai dalam definisi tabel */
{
   Elmt(T, 0) = X;
   for (int i = 1; i <= Neff(T); i++) {
       if (Elmt(T, i) == X) return true;
   }
   return false;
}

/* ********** NILAI EKSTREM ********** */
ElType ValMax (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum tabel */
{
    ElType maks = Elmt(T, IdxMin);
    for (int i = IdxMin; i <= Neff(T); i++) {
        if (Elmt(T, i) > maks) {
            maks = Elmt(T, i);
        }
    }
    return maks;
}
ElType ValMin (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum tabel */
{
    ElType mins = Elmt(T, IdxMin);
    for (int i = IdxMin; i <= Neff(T); i++) {
        if (Elmt(T, i) < mins) {
            mins = Elmt(T, i);
        }
    }
    return mins;
}
/* *** Mengirimkan indeks elemen bernilai ekstrem *** */
IdxType IdxMaxTab (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai maksimum pada tabel */
{
    ElType maks = ValMax(T);
    for (int i = IdxMin; i <= Neff(T); i++) {
        if (Elmt(T, i) == maks) return i;
    }
}
IdxType IdxMinTab (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai minimum pada tabel */
{
    int mins = ValMin(T);
    for (int i = IdxMin; i <= Neff(T); i++) {
        if (Elmt(T, i) == mins) return i;
    }
}
/* ********** OPERASI LAIN ********** */
void CopyTab (TabInt Tin, TabInt * Tout)
/* I.S. Tin terdefinisi, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (elemen dan ukuran identik) */
/* Proses : Menyalin isi Tin ke Tout */
{
    Neff(*Tout) = Neff(Tin);
    for (int i = IdxMin; i <= Neff(Tin); i++) {
        Elmt(*Tout, i) = Elmt(Tin, i);
    }
}
TabInt InverseTab (TabInt T)
/* Menghasilkan tabel dengan urutan tempat yang terbalik, yaitu : */
/* elemen pertama menjadi terakhir, */
/* elemen kedua menjadi elemen sebelum terakhir, dst.. */
/* Tabel kosong menghasilkan tabel kosong */
{
    TabInt hasil;
    Neff(hasil) = Neff(T);
    for (int i = IdxMin; i <= Neff(T); i++) {
        Elmt(hasil, Neff(T) - i + 1) = Elmt(T, i);
    }
    return hasil;
}
boolean IsSimetris (TabInt T)
/* Menghasilkan true jika tabel simetrik */
/* Tabel disebut simetrik jika: */
/*      elemen pertama = elemen terakhir, */
/*      elemen kedua = elemen sebelum terakhir, dan seterusnya */
/* Tabel kosong adalah tabel simetris */
{
    for (int i = IdxMin; i <= Neff(T); i++) {
        if (Elmt(T, Neff(T) - i + 1) != Elmt(T, i)) return false;
    }
    return true;
}
/* ********** SORTING ********** */
void MaxSortDesc (TabInt * T)
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menurun dengan Maximum Sort */
/* Proses : mengurutkan T sehingga elemennya menurun/mengecil */
/*          tanpa menggunakan tabel kerja */
{
    int n = Neff(*T);
    for (int i = IdxMin; i <= n; i++) {
        for (int j = IdxMin; j <= n - 1; j++) {
            if (TI(*T)[j] < TI(*T)[j + 1]) {
                ElType temp = TI(*T)[j];
                TI(*T)[j] = TI(*T)[j + 1];
                TI(*T)[j + 1] = temp;
            }
        }
    }
}
void InsSortAsc (TabInt * T)
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menaik dengan Insertion Sort */
/* Proses : mengurutkan T sehingga elemennya menaik/membesar */
/*          tanpa menggunakan tabel kerja */
{
    IdxType n = Neff(*T);
    for (int i = IdxMin; i <= n; i++) {
        for (int j = IdxMin; j <= n - 1; j++) {
            if (TI(*T)[j] > TI(*T)[j + 1]) {
                ElType temp = TI(*T)[j];
                TI(*T)[j] = TI(*T)[j + 1];
                TI(*T)[j + 1] = temp;
            }
        }
    }
}
/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (TabInt * T, ElType X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
    if (Neff(*T) == IdxMax) return;
    Neff(*T)++;
    Elmt(*T, Neff(*T)) = X;
}
void AddEli (TabInt * T, ElType X, IdxType i)
/* Menambahkan X sebagai elemen ke-i tabel tanpa mengganggu kontiguitas
   terhadap elemen yang sudah ada */
/* I.S. Tabel tidak kosong dan tidak penuh */
/*      i adalah indeks yang valid. */
/* F.S. X adalah elemen ke-i T yang baru */
/* Proses : Geser elemen ke-i+1 s.d. terakhir */
/*          Isi elemen ke-i dengan X */
{
    Neff(*T)++;
    for (int j = Neff(*T); j >= i + 1; j--) {
        Elmt(*T, j) = Elmt(*T, j - 1);
    }
    Elmt(*T, i) = X;
}
/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl (TabInt * T, ElType * X)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{
    *X = Elmt(*T, Neff(*T));
    Neff(*T)--;
}
void DelEli (TabInt * T, IdxType i, ElType * X)
/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
/*          Kurangi elemen efektif tabel */
{
    *X = Elmt(*T, i);
    Neff(*T)--;
    for (int j = i; j <= Neff(*T); j++) {
        Elmt(*T, j) = Elmt(*T, j + 1);
    }
}
/* ********** TABEL DGN ELEMEN UNIK (SETIAP ELEMEN HANYA MUNCUL 1 KALI) ********** */
void AddElUnik (TabInt * T, ElType X)
/* Menambahkan X sebagai elemen terakhir tabel, pada tabel dengan elemen unik */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/*      dan semua elemennya bernilai unik, tidak terurut */
/* F.S. Jika tabel belum penuh, menambahkan X sbg elemen terakhir T,
        jika belum ada elemen yang bernilai X.
    Jika sudah ada elemen tabel yang bernilai X maka I.S. = F.S.
    dan dituliskan pesan "nilai sudah ada" */
/* Proses : Cek keunikan dengan sequential search dengan sentinel */
/*          Kemudian tambahkan elemen jika belum ada */
{
    if (Neff(*T) == 0) {
        Elmt(*T, ++Neff(*T)) = X;
        return;
    }
    for (int i = IdxMin; i <= Neff(*T); i++) {
        if (Elmt(*T, i) == X) {
            printf("nilai sudah ada\n");
            return;
        }
    }
    Elmt(*T, ++Neff(*T)) = X;
}
/* ********** TABEL DGN ELEMEN TERURUT MEMBESAR ********** */
IdxType SearchUrut (TabInt T, ElType X)
/* Prekondisi: Tabel T boleh kosong. Jika tidak kosong, elemen terurut membesar. */
/* Mengirimkan indeks di mana harga X dengan indeks terkecil diketemukan */
/* Mengirimkan IdxUndef jika tidak ada elemen tabel bernilai X */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel kosong */
{
    if (Neff(T) == 0) return IdxUndef;
    for (int i = IdxMin; i <= Neff(T); i++) {
        if (Elmt(T, i) == X) return i;
    }
    return IdxUndef;
}
ElType MaxUrut (TabInt T)
/* Prekondisi : Tabel tidak kosong, elemen terurut membesar */
/* Mengirimkan nilai maksimum pada tabel */
{
    return Elmt(T, Neff(T));
}
ElType MinUrut (TabInt T)
/* Prekondisi : Tabel tidak kosong, elemen terurut membesar */
/* Mengirimkan nilai minimum pada tabel*/
{
    return Elmt(T, IdxMin);
}
void MaxMinUrut (TabInt T, ElType * Max, ElType * Min)
/* I.S. Tabel T tidak kosong, elemen terurut membesar */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
{
    *Min = MinUrut(T);
    *Max = MaxUrut(T);
}
void Add1Urut (TabInt * T, ElType X)
/* Menambahkan X tanpa mengganggu keterurutan nilai dalam tabel */
/* Nilai dalam tabel tidak harus unik. */
/* I.S. Tabel T boleh kosong, boleh penuh. */
/*      Jika tabel isi, elemennya terurut membesar. */
/* F.S. Jika tabel belum penuh, menambahkan X. */
/*      Jika tabel penuh, maka tabel tetap. */
/* Proses : Search tempat yang tepat sambil geser */
/*          Insert X pada tempat yang tepat tersebut tanpa mengganggu keterurutan */
{
    if (Neff(*T) < IdxMax) {
        Neff(*T)++;
        Elmt(*T, Neff(*T)) = X;
        InsSortAsc(T);
    }
}
void Del1Urut (TabInt * T, ElType X)
/* Menghapus X yang pertama kali (pada indeks terkecil) yang ditemukan */
/* I.S. Tabel tidak kosong */
/* F.S. Jika ada elemen tabel bernilai X , */
/*      maka banyaknya elemen tabel berkurang satu. */
/*      Jika tidak ada yang bernilai X, tabel tetap. */
/*      Setelah penghapusan, elemen tabel tetap kontigu! */
/* Proses : Search indeks ke-i dengan elemen ke-i = X. */
/*          Delete jika ada. */
{
    for (int i = IdxMin; i <= Neff(*T); i++) {
        if (Elmt(*T, i) == X) {
            DelEli(T, i, &X);
            return;
        }
    }
}
