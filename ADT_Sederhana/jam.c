// Muhammad Hasan - 13518012
// Tanggal 		: 28/08/2019
// Deskripsi 	: Membuat ADT Sederhana, yaitu ADT Jam

#include <stdio.h>
#include "jam.h"

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsJAMValid (int H, int M, int S)
/* Mengirim true  jika H,M,S dapat membentuk J yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */
{
	return (0 <= H && H <= 23 && 0 <= M && M <= 59 && 0 <= S && S <= 59);
}

/* *** Konstruktor: Membentuk sebuah JAM dari komponen-komponennya *** */
JAM MakeJAM (int HH, int MM, int SS)
/* Membentuk sebuah JAM dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk JAM */
{
	JAM hasilJam;
	Hour(hasilJam) = HH;
	Minute(hasilJam) = MM;
	Second(hasilJam) = SS;
	return hasilJam;
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaJAM (JAM * J)
/* I.S. : J tidak terdefinisi */
/* F.S. : J terdefinisi dan merupakan jam yang valid */
/* Proses : mengulangi membaca komponen HH, MM, SS sehingga membentuk J */
/* yang valid. Tidak mungkin menghasilkan J yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen HH, MM, SS
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika JAM tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
   diulangi hingga didapatkan jam yang valid. */
/* Contoh:
   60 3 4
   Jam tidak valid
   1 3 4
   --> akan terbentuk JAM <1,3,4> */
{
	int HH, MM, SS;
	while (1) {
		scanf("%d %d %d", &HH, &MM, &SS);
		if (IsJAMValid(HH,MM,SS)) {
			*J = MakeJAM(HH, MM, SS);
			break;
		} else {
			printf("Jam tidak valid\n");
		}
	}
}

void TulisJAM (JAM J)
/* I.S. : J sembarang */
/* F.S. :   Nilai J ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen J ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.
   Jika jam / menit / detik hanya satu digit, tuliskan satu digit tanpa 0 di depannya. */

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
{
	printf("%d:%d:%d", Hour(J), Minute(J), Second(J));
}
long JAMToDetik (JAM J)
/* Diberikan sebuah JAM, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */
{
	return (3600 * Hour(J) + 60 * Minute(J) + Second(J));
}
JAM DetikToJAM (long N)
/* Mengirim  konversi detik ke JAM */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus:
   N1 = N mod 86400, baru N1 dikonversi menjadi JAM */
{
	N = (N % 86400 + 86400) % 86400;
	int HH = N / 3600;
	N %= 3600;
	int MM = N / 60;
	N %= 60;
	int SS = N;
	return MakeJAM(HH, MM, SS);
}
/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean JEQ (JAM J1, JAM J2)
/* Mengirimkan true jika J1=J2, false jika tidak */
{
	return (Hour(J1) == Hour(J2) && Minute(J1) == Minute(J2) && Second(J1) == Second(J2));
}
boolean JNEQ (JAM J1, JAM J2)
/* Mengirimkan true jika J1 tidak sama dengan J2 */
{
	return (!(JEQ(J1, J2)));
}
boolean JLT (JAM J1, JAM J2)
/* Mengirimkan true jika J1<J2, false jika tidak */
{
	return (JAMToDetik(J1) < JAMToDetik(J2));
}
boolean JGT (JAM J1, JAM J2)
/* Mengirimkan true jika J1>J2, false jika tidak */
/* *** Operator aritmatika JAM *** */
{
	return (JAMToDetik(J1) > JAMToDetik(J2));
}
JAM NextDetik (JAM J)
/* Mengirim 1 detik setelah J dalam bentuk JAM */
{
	long hasilDetik = JAMToDetik(J);
	hasilDetik++;
	JAM hasilJam = DetikToJAM(hasilDetik);
	return hasilJam;
}
JAM NextNDetik (JAM J, int N)
/* Mengirim N detik setelah J dalam bentuk JAM */
{
	long hasilDetik = JAMToDetik(J);
	hasilDetik += N;
	JAM hasilJam = DetikToJAM(hasilDetik);
	return hasilJam;
}
JAM PrevDetik (JAM J)
/* Mengirim 1 detik sebelum J dalam bentuk JAM */
{
	long hasilDetik = JAMToDetik(J);
	hasilDetik--;
	JAM hasilJam = DetikToJAM(hasilDetik);
	return hasilJam;
}
JAM PrevNDetik (JAM J, int N)
/* Mengirim N detik sebelum J dalam bentuk JAM */
/* *** Kelompok Operator Aritmetika *** */
{
	long hasilDetik = JAMToDetik(J);
	hasilDetik -= N;
	JAM hasilJam = DetikToJAM(hasilDetik);
	return hasilJam;
}
long Durasi (JAM JAw, JAM JAkh)
/* Mengirim JAkh-JAw dlm Detik, dengan kalkulasi */
/* Jika JAw > JAkh, maka JAkh adalah 1 hari setelah JAw */
{
	long detikw = JAMToDetik(JAw), detikh = JAMToDetik(JAkh);
	long hasil = (detikh - detikw);
	hasil = (hasil % 86400 + 86400) % 86400;
	return hasil;
}
