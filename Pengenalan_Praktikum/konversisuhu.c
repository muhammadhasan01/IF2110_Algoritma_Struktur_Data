// Muhammad Hasan - 13518012
// Tanggal : 27/08/2019
// Program Konversi Suhu - Mengkonversi Suhu Celcius ke Fahrenhait, Reamur, dan Kelvin

#include<stdio.h>

int main() {
	float suhu;
	char tipe;
	scanf("%f %c", &suhu, &tipe);
	if (tipe == 'R') {
		suhu *= 0.8;
	} else if (tipe == 'F') {
		suhu = (1.8) * suhu + 32;
	} else if (tipe == 'K') {
		suhu += 273.15;
	}
	printf("%0.2f\n", suhu);
	return 0;
}
