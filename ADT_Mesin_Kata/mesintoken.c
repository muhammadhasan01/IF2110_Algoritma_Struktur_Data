// NAMA       : Muhammad Hasan
// NIM        : 13518012
// Tanggal    : 26/09/2019
// Deskripsi  : Mengimplementasikan Mesintoken


#include "boolean.h"
#include "mesintoken.h"
#include "mesinkar.h"
#include <stdio.h>
boolean EndToken;
Token CToken;

void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
{
  while (CC == BLANK && CC != MARK) ADV();
}
void STARTTOKEN()
/* I.S. : CC sembarang
   F.S. : EndToken = true, dan CC = MARK;
          atau EndToken = false, CToken adalah Token yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir Token */
{
  START();
  IgnoreBlank();
  if (CC == MARK) {
    EndToken = true;
  } else {
    EndToken = false;
    SalinToken();
  }
}
void ADVTOKEN()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CToken adalah Token terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, maka EndToken = true
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{
  IgnoreBlank();
  if (CC == MARK) {
    EndToken = true;
  } else {
    SalinToken();
    IgnoreBlank();
  }
}
void SalinToken()
/* Mengakuisisi Token dan menyimpan hasilnya dalam CToken
   I.S. : CC adalah karakter pertama dari Token
   F.S. : CToken berisi Token yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
  int i = 1;
  int hasil = -1, res = 0;
  do {
    if ('0' <= CC && CC <= '9') {
      CToken.tkn = 'b';
      res = (10 * res) + (CC - '0');
    } else {
      CToken.tkn = CC;
    }
    ADV();
  } while (CC != MARK && CC != BLANK && i <= NMax);
  if (CToken.tkn == 'b') hasil = res;
  CToken.val = hasil;
}