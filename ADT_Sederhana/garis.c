// Muhammad Hasan - 13518012
// ADT Sederhana Garis

#include <stdio.h>
#include "garis.h"
#include "point.h"
#include <math.h>

void MakeGARIS (POINT P1, POINT P2, GARIS * L)
/* I.S. P1 dan P2 terdefinisi */
/* F.S. L terdefinisi dengan L.PAw = P1 dan L.PAkh = P2 */
/* Membentuk sebuah L dari komponen-komponennya */

/* ***************************************************************** */
/* KELOMPOK INTERAKSI DENGAN I/O DEVICE, BACA/TULIS                  */
/* ***************************************************************** */
{
	PAwal(*L) = P1;
	PAkhir(*L) = P2;
}
void BacaGARIS (GARIS * L)
/* I.S. sembarang */
/* F.S. L terdefinisi sebagai GARIS yang valid */
/* Proses : mengulangi membaca dua buah nilai P1 dan P2 sehingga dapat 
   membentuk GARIS yang valid 
   GARIS disebut valid jika titik awal tidak sama dengan titik akhirnya. */
/* Jika pembacaan garis tidak valid, diberikan pesan kesalahan: 
   "Garis tidak valid" */
/* Contoh:
   2 3
   2 3
   Garis tidak valid
   2 3
   3 3 
   --> terbentuk garis L dengan L.PAw = <2,3> dan L.PAkh = <3,3> */
{
	float x1, y1, x2, y2;
	while (1) {
		scanf("%f %f", &x1, &y1);
		scanf("%f %f", &x2, &y2);
		if (x1 == x2 && y1 == y2) {
			printf("Garis tidak valid\n");
		} else {
			POINT p1, p2;
			Absis(p1) = x1;
			Ordinat(p1) = y1;
			Absis(p2) = x2;
			Ordinat(p2) = y2;
			MakeGARIS(p1, p2, L);
			break;
		}
	}
	
}
void TulisGARIS (GARIS L)
/* I.S. L terdefinisi */
/* F.S. L tertulis di layar dengan format "((x1,y1),(x2,y2))" 
   tanpa tambahan karakter apa pun di depan, di tengah, atau di belakang,
   termasuk spasi dan enter */

/* *** Kelompok operasi garis *** */
{
	float x1 = Absis(PAwal(L));
	float y1 = Ordinat(PAwal(L));
	float x2 = Absis(PAkhir(L));
	float y2 = Ordinat(PAkhir(L));
	printf("((%.2f,%.2f),(%.2f,%.2f))",x1,y1,x2,y2);
}
float PanjangGARIS (GARIS L)
/* Menghitung panjang garis L : jarak antara PAwal dengan PAkhir */
{
	return Panjang(PAwal(L), PAkhir(L));
}
float Gradien (GARIS L)
/* Mengembalikan Gradien (m) dari L */
/* Gradien garis yang melalui (x1,y1) dan (x2,y2) adalah: (y2-y1)/(x2-x1) */
/* Prekondisi : x1 != x2 */
{
	float x1 = Absis(PAwal(L));
	float y1 = Ordinat(PAwal(L));
	float x2 = Absis(PAkhir(L));
	float y2 = Ordinat(PAkhir(L));
	return (y2 - y1) / (x2 - x1);
}
void GeserGARIS (GARIS * L, float deltaX, float deltaY)
/* I.S. L terdefinisi */
/* F.S. L digeser sebesar deltaX ke arah sumbu X dan sebesar deltaY ke arah sumbu Y */
/* Proses : PAw dan PAkh digeser. */
{
	Geser(&PAwal(*L), deltaX, deltaY);
	Geser(&PAkhir(*L), deltaX, deltaY);
}

/* *** Kelompok predikat *** */
boolean IsTegakLurus (GARIS L1, GARIS L2)
/* Menghasilkan true jika L1 tegak lurus terhadap L2 */
/* Dua garis saling tegak lurus jika hasil perkalian kedua gradiennya = -1 */
{
	return (Gradien(L1) * Gradien(L2) == -1);
}
boolean IsSejajar (GARIS L1, GARIS L2)
/* Menghasilkan true jika L "sejajar" terhadap L1 */
/* Dua garis saling sejajar jika memiliki gradien yang sama */
{
	return (Gradien(L1) == Gradien(L2));
}
