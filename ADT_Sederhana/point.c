// Muhammad Hasan - 13518012
// Tanggal : 28/08/2019
// Deskripsi : Membuat ADT Sederhana, yakni point

#include <stdio.h>
#include <math.h>
#include "point.h"

/* *** DEFINISI PROTOTIPE PRIMITIF *** */

#define pi 3.1415926535897932384626433832795

/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (float X, float Y)
/* Membentuk sebuah POINT dari komponen-komponennya */
{
	POINT hasilPoint;
	Absis(hasilPoint) = X;
	Ordinat(hasilPoint) = Y;
	return hasilPoint;
}
/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void BacaPOINT (POINT * P)
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
{
	float x, y;
	scanf("%f %f", &x, &y);
	*P = MakePOINT(x, y);
}

void TulisPOINT (POINT P)
/* Nilai P ditulis ke layar dengan format "(X,Y)"
   tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */
{
	printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}
/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2)
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
{
	return (Absis(P1) == Absis(P2) && Ordinat(P1) == Ordinat(P2));
}
boolean NEQ (POINT P1, POINT P2)
/* Mengirimkan true jika P1 tidak sama dengan P2 */
{
	return (!EQ(P1, P2));
}

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P)
/* Menghasilkan true jika P adalah titik origin */
{
	return (Absis(P) == 0 && Ordinat(P) == 0);
}
boolean IsOnSbX (POINT P)
/* Menghasilkan true jika P terletak Pada sumbu X */
{
	return (Ordinat(P) == 0);
}
boolean IsOnSbY (POINT P)
/* Menghasilkan true jika P terletak pada sumbu Y */
{
	return (Absis(P) == 0);
}
int Kuadran (POINT P)
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */
{
	float x = Absis(P), y = Ordinat(P);
	if (x > 0 && y > 0) {
		return 1;
	} else if (x < 0 && y > 0) {
		return 2;
	} else if (x < 0 && y < 0) {
		return 3;
	} else if (x > 0 && y < 0) {
		return 4;
	}
}
/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
POINT NextX (POINT P)
/* Mengirim salinan P dengan absis ditambah satu */
{
	return MakePOINT(Absis(P) + 1, Ordinat(P));
}
POINT NextY (POINT P)
/* Mengirim salinan P dengan ordinat ditambah satu */
{
	return MakePOINT(Absis(P), Ordinat(P) + 1);
}
POINT PlusDelta (POINT P, float deltaX, float deltaY)
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
{
	return MakePOINT(Absis(P) + deltaX, Ordinat(P) + deltaY);
}
POINT MirrorOf (POINT P, boolean SbX)
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
{
	return (SbX ? MakePOINT(Absis(P), -Ordinat(P)) : MakePOINT(-Absis(P), Ordinat(P)));
}
float Jarak0 (POINT P)
/* Menghitung jarak P ke (0,0) */
{
	float x = Absis(P), y = Ordinat(P);
	return sqrt(x * x + y * y);
}
float Panjang (POINT P1, POINT P2)
/* Menghitung panjang atau jarak dari P1 ke P2 */
{
	float selisihX = Absis(P1) - Absis(P2);
	float selisihY = Ordinat(P1) - Ordinat(P2);
	return sqrt(selisihX * selisihX + selisihY * selisihY);
}
void Geser (POINT *P, float deltaX, float deltaY)
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
{
	*P = PlusDelta(*P, deltaX, deltaY);
}
void GeserKeSbX (POINT *P)
/* I.S. P terdefinisi */
/* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
/* Proses : P digeser ke sumbu X. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */
{
	Ordinat(*P) = 0;
}
void GeserKeSbY (POINT *P)
/* I.S. P terdefinisi*/
/* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
/* Proses : P digeser ke sumbu Y. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */
{
	Absis(*P) = 0;
}
void Mirror (POINT *P, boolean SbX)
/* I.S. P terdefinisi */
/* F.S. P dicerminkan tergantung nilai SbX atau SbY */
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */
{
	POINT temp = MirrorOf(*P, SbX);
	*P = temp;
}
void Putar (POINT *P, float Sudut)
/* I.S. P terdefinisi */
/* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) searah jarum jam*/
{
	Sudut *= - pi / 180; // Sudut dijadikan radian
	float hasilRotasiX = Absis(*P) * cos(Sudut) - Ordinat(*P) * sin(Sudut);
	float hasilRotasiY = Absis(*P) * sin(Sudut) + Ordinat(*P) * cos(Sudut);
	*P = MakePOINT(hasilRotasiX, hasilRotasiY);
}
