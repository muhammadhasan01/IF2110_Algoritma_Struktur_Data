#include <stdio.h>
#include <math.h>
#include "vector.h"

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk VECTOR *** */
VECTOR MakeVector(float x, float y)
/* Membentuk sebuah VECTOR dengan komponen absis x dan
   komponen ordinat y */
{
	VECTOR hasilVektor;
	Absis(hasilVektor) = x;
	Ordinat(hasilVektor) = y;
	return hasilVektor;
}
/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void TulisVector(VECTOR v)
/* Nilai v ditulis ke layar dengan format "<X,Y>"
   tanpa spasi, enter, atau karakter lain di depan, belakang, atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. v terdefinisi */
/* F.S. v tertulis di layar dengan format "<X,Y>" */
{
	printf("<%.2f,%.2f>", Absis(v), Ordinat(v));
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
float Magnitude(VECTOR v)
/* Menghasilkan magnitudo dari vector, yakni sqrt(v.x^2+v.y^2) */
{
	return sqrt(Absis(v) * Absis(v) + Ordinat(v) * Ordinat(v));
}
VECTOR Add(VECTOR a, VECTOR b)
/* Menghasilkan sebuah vector yang merupakan hasil a + b.
   Komponen absis vector hasil adalah vector pertama
   ditambah vector kedua, begitu pula dengan ordinatnya */
{
	VECTOR ret;
	Absis(ret) = Absis(a) + Absis(b);
	Ordinat(ret) = Ordinat(a) + Ordinat(b);
	return ret;
}
VECTOR Substract(VECTOR a, VECTOR b)
/* Menghasilkan sebuah vector yang merupakan hasil a - b.
   Komponen absis vector hasil adalah vector pertama
   dikurangi vector kedua, begitu pula dengan ordinatnya */
{
	VECTOR ret;
	Absis(ret) = Absis(a) - Absis(b);
	Ordinat(ret) = Ordinat(a) - Ordinat(b);
	return ret;
}
float Dot(VECTOR a, VECTOR b)
/* Menghasilkan perkalian dot vector, yakni a.x * b.x + a.y * b.y */
{
	return (Absis(a) * Absis(b) + Ordinat(a) * Ordinat(b));
}
VECTOR Multiply(VECTOR v, float s)
/* Menghasilkan perkalian skalar vector dengan s, yakni
   (s * a.x, s * a.y) */
{
	VECTOR ret;
	Absis(ret) = s * Absis(v);
	Ordinat(ret) = s * Ordinat(v);
	return ret;
}
