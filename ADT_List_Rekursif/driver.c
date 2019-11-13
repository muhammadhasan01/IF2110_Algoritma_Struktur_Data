#include <stdio.h>
#include "delNFromEnd.c"
#include "listrek.c"

int main() {

    List L = Alokasi(1);
    L = KonsB(L, 3);
    L = KonsB(L, 5);
    PrintList(L);
    printf("\n");
    List K = delNFromEnd(L, 1);
    PrintList(K);

    return 0;
}
