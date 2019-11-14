/* NAMA 		: Muhammad Hasan */
/* NIM			: 13518012 */
/* DEKSRIPSI	: InvertBtree.c */
#include <stdio.h>
#include "bintree.h"
#include "listrek.h"

void InvertBtree(BinTree *P) {
	if (IsTreeEmpty(*P)) return;
	BinTree Temp = Left(*P);
	Left(*P) = Right(*P);
	Right(*P) = Temp;
	InvertBtree(&Left(*P));
	InvertBtree(&Right(*P));
}