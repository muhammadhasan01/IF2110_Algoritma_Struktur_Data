#include <stdio.h>
#include "matriks.c"

int main() {
    MATRIKS m;
    MakeMATRIKS(4, 4, &m);
    BacaMATRIKS(&m, 4, 4);
    printf("%.2f", Determinan(m));

    return 0;
}
