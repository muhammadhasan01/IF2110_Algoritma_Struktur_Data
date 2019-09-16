// Muhammad Hasan - 13518012
// Tanggal  : 15/09/2019

#include <stdio.h>
#include "matriks.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M)
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
    NBrsEff(*M) = NB;
    NKolEff(*M) = NK;
}
/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
{
    return (BrsMin <= i && i <= BrsMax && KolMin <= j && j <= KolMax);
}
/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terkecil M */
{
    return BrsMin;
}
indeks GetFirstIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terkecil M */
{
    return KolMin;
}
indeks GetLastIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terbesar M */
{
    return NBrsEff(M);
}
indeks GetLastIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terbesar M */
{
    return NKolEff(M);
}
boolean IsIdxEff (MATRIKS M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
    return (GetFirstIdxBrs(M) <= i && i <= GetLastIdxBrs(M) && GetFirstIdxKol(M) <= j && j <= GetLastIdxKol(M));
}
ElType GetElmtDiagonal (MATRIKS M, indeks i)
/* Mengirimkan elemen M(i,i) */
{
    return Elmt(M, i, i);
}
/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl)
/* Melakukan assignment MHsl  MIn */
{
    NBrsEff(*MHsl) = NBrsEff(MIn);
    NKolEff(*MHsl) = NKolEff(MIn);

    for (int i = GetFirstIdxBrs(MIn); i <= GetLastIdxBrs(MIn); i++) {
        for (int j = GetFirstIdxKol(MIn); j <= GetLastIdxKol(MIn); j++) {
            Elmt(*MHsl, i, j) = Elmt(MIn, i, j);
        }
    }
}
/* ********** KELOMPOK BACA/TULIS ********** */
void BacaMATRIKS (MATRIKS * M, int NB, int NK)
/* I.S. IsIdxValid(NB,NK) */
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10
*/
{
    NBrsEff(*M) = NB;
    NKolEff(*M) = NK;
    for (int i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++) {
        for (int j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++) {
            scanf("%d", &Elmt(*M, i, j));
        }
    }
}
void TulisMATRIKS (MATRIKS M)
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
    for (int i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
        for (int j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
            printf("%d", Elmt(M, i, j));
            if (j < GetLastIdxKol(M)) printf(" ");
        }
        if (i != GetLastIdxBrs(M)) printf("\n");
    }
}
/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */
{
    MATRIKS ret;
    NBrsEff(ret) = NBrsEff(M1);
    NKolEff(ret) = NKolEff(M1);
    for (int i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++) {
        for (int j = GetFirstIdxKol(M1); j <= GetLastIdxKol(M1); j++) {
            Elmt(ret, i, j) = Elmt(M1, i, j) + Elmt(M2, i, j);
        }
    }
    return ret;
}
MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */
{
    MATRIKS ret;
    NBrsEff(ret) = NBrsEff(M1);
    NKolEff(ret) = NKolEff(M1);
    for (int i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++) {
        for (int j = GetFirstIdxKol(M1); j <= GetLastIdxKol(M1); j++) {
            Elmt(ret, i, j) = Elmt(M1, i, j) - Elmt(M2, i, j);
        }
    }
    return ret;
}
MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
{
    MATRIKS ret;
    NBrsEff(ret) = NBrsEff(M1);
    NKolEff(ret) = NKolEff(M2);

    for (int i = GetFirstIdxBrs(ret); i <= GetLastIdxBrs(ret); i++) {
        for (int j = GetFirstIdxKol(ret); j <= GetLastIdxKol(ret); j++) {
            Elmt(ret, i, j) = 0;
        }
    }

    for (int i = GetFirstIdxBrs(ret); i <= GetLastIdxBrs(ret); i++) {
        for (int j = GetFirstIdxKol(ret); j <= GetLastIdxKol(ret); j++) {
            for (int k = GetFirstIdxKol(M1); k <= GetLastIdxKol(M1); k++) {
                Elmt(ret, i, j) += Elmt(M1, i, k) * Elmt(M2, k, j);
            }
        }
    }

    return ret;
}
MATRIKS KaliKons (MATRIKS M, ElType X)
/* Mengirim hasil perkalian setiap elemen M dengan X */
{
    MATRIKS ret;
    NBrsEff(ret) = NBrsEff(M);
    NKolEff(ret) = NKolEff(M);
    for (int i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
        for (int j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
            Elmt(ret, i, j) = Elmt(M, i, j) * X;
        }
    }
    return ret;
}
void PKaliKons (MATRIKS * M, ElType K)
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */
{
    *M = KaliKons(*M, K);
}
/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2)
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
{
    if (NBrsEff(M1) != NBrsEff(M2)) return false;
    if (NKolEff(M1) != NKolEff(M2)) return false;
    for (int i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++) {
        for (int j = GetFirstIdxKol(M1); j <= GetLastIdxKol(M1); j++) {
            if (Elmt(M1, i, j) != Elmt(M2, i, j)) return false;
        }
    }
    return true;
}
boolean NEQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 tidak sama dengan M2 */
{
    return (!EQ(M1, M2));
}
boolean EQSize (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
{
    return (NBrsEff(M1) == NBrsEff(M2) && NKolEff(M1) == NKolEff(M2));
}
/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M)
/* Mengirimkan banyaknya elemen M */
{
    return (NBrsEff(M) * NKolEff(M));
}
/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M)
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
{
    return (NBrsEff(M) == NKolEff(M));
}
boolean IsSimetri (MATRIKS M)
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M)
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
{
    if (!IsBujurSangkar(M)) return false;
    for (int i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
        for (int j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
            if (Elmt(M, i, j) != Elmt(M, j, i)) return false;
        }
    }
    return true;
}
boolean IsSatuan (MATRIKS M)
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
{
    if (!IsBujurSangkar(M)) return false;
    for (int i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
        for (int j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
            if (i == j && Elmt(M, i, j) != 1) {
                return false;
            } else if (i != j && Elmt(M, i, j) != 0) {
                return false;
            }
        }
    }
    return true;
}
boolean IsSparse (MATRIKS M)
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi:
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
{
    int cnt = 0;
    for (int i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
        for (int j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
            if (Elmt(M, i, j) != 0) cnt++;
        }
    }
    return (NBElmt(M) >= cnt * 20);
}
MATRIKS Inverse1 (MATRIKS M)
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
{
    MATRIKS ret;
    NBrsEff(ret) = NBrsEff(M);
    NKolEff(ret) = NKolEff(M);
    for (int i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
        for (int j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
            Elmt(ret, i, j) = -Elmt(M, i, j);
        }
    }
    return ret;
}
float Determinan (MATRIKS M)
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */
{
    float hasil = 1;
    float MF[105][105];
    for (int i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
        for (int j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
            MF[i][j] = Elmt(M, i, j);
        }
    }
    for (int i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
        if (MF[i][i] == 0) {
            boolean tukar = false;
            for (int j = i + 1; j <= GetLastIdxBrs(M); j++) {
                if (MF[j][j] != 0) {
                    for (int k = GetFirstIdxKol(M); k <= GetLastIdxKol(M); k++) MF[0][k] = MF[i][k];
                    for (int k = GetFirstIdxKol(M); k <= GetLastIdxKol(M); k++) MF[i][k] = MF[j][k];
                    for (int k = GetFirstIdxKol(M); k <= GetLastIdxKol(M); k++) MF[j][k] = MF[0][k];
                    hasil *= -1;
                    tukar = true;
                    break;
                }
            }
            if (!tukar) return 0;
        }
    }
    for (int i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
        float temp = MF[i][i];
        hasil *= temp;
        if (hasil == 0) return hasil;
        for (int k = GetFirstIdxKol(M); k <= GetLastIdxKol(M); k++) MF[i][k] /= temp;
        for (int j = i + 1; j <= GetLastIdxBrs(M); j++) {
            temp = MF[j][i];
            for (int k = GetFirstIdxKol(M); k <= GetLastIdxKol(M); k++) MF[j][k] -= MF[i][k] * temp;
        }
    }
    return hasil;
}
void PInverse1 (MATRIKS * M)
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
{
    *M = Inverse1(*M);
}
void Transpose (MATRIKS * M)
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
{
    MATRIKS ret;
    CopyMATRIKS(*M, &ret);
    NBrsEff(*M) = NKolEff(ret);
    NKolEff(*M) = NBrsEff(ret);
    for (int i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++) {
        for (int j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++) {
            Elmt(*M, i, j) = Elmt(ret, j, i);
        }
    }
}
