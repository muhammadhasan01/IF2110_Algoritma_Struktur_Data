// Nama/NIM		: Muhammad Hasan/13518012
// Tanggal 		: 29/08/2019
// Topik		: ADT
// Deskripsi	: Program jam yang menggunakan jam.c untuk mengetahui hal yang diinginkan

#include <stdio.h>
#include "jam.h"

/* PROGRAM UTAMA */
int main() {

	/* KAMUS */
	int N; // Banyaknya pasangan data yang akan dibaca

	/* ALGORITMA */
	scanf("%d", &N);

	JAM jamPalingAwal, jamPalingAkhir;
	jamPalingAwal = MakeJAM(23, 59, 59);
	jamPalingAkhir = MakeJAM(0, 0, 0);

	for (int i = 1; i <= N; i++) {
		JAM jamPertama, jamKedua;
		printf("[%d]\n", i);
		BacaJAM(&jamPertama);
		BacaJAM(&jamKedua);

		// Kita asumsikan jamPertama selalu lebih besar
		// Jika jamKedua lebih besar kita swap jamPertama dengan jamKedua
		if (JLT(jamPertama, jamKedua)) {
			JAM temp = jamKedua;
			jamKedua = jamPertama;
			jamPertama = temp;
		}

		if (JLT(jamPalingAkhir, jamPertama)) jamPalingAkhir = jamPertama;
		if (JLT(jamKedua, jamPalingAwal)) jamPalingAwal = jamKedua;

		printf("%ld\n", Durasi(jamKedua, jamPertama));
	}
	TulisJAM(jamPalingAwal);
	printf("\n");
	TulisJAM(jamPalingAkhir);
	printf("\n");

	return 0;
}
