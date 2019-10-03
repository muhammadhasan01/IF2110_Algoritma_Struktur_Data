// NAMA       : Muhammad Hasan
// NIM        : 13518012
// Tanggal    : 26/09/2019
// Deskripsi  : Mencari Kata Tertentu

#include "mesinkata.h"
#include <stdio.h>

Kata pattern;
int hasil;

Kata copyKata() {
  Kata ret;
  ret.Length = CKata.Length;
  for (int i = 1; i <= ret.Length; i++) {
    ret.TabKata[i] = CKata.TabKata[i];
  }
  return ret;
}

void mulai() {
  START();
  IgnoreBlank();
  SalinKata();
  pattern = copyKata();
}

int cariBanyakKata(Kata str) {
  if (str.Length < pattern.Length) return 0;
  int ret = 0;
  for (int i = 1; i <= str.Length; i++) {
    if (i + pattern.Length - 1 > str.Length) break;
    int ok = 1;
    for (int j = 1; j <= pattern.Length; j++) {
      if (pattern.TabKata[j] == str.TabKata[i + j - 1]) continue;
      ok = 0;
      break;
    }
    if (ok) ret++;
  }
  return ret;
}

void cariKata() {
  IgnoreBlank();
  if (CC == MARK) {
    EndKata = true;
  } else {
    SalinKata();
    Kata str = copyKata();
    hasil += cariBanyakKata(str);
  }
  if (EndKata == false) cariKata();
}

int main() {

  mulai();
  cariKata();
  printf("%d\n", hasil);

  return 0;
}