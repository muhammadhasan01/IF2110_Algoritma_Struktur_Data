#include <stdio.h>
#include "arraydinpos.h"

int main() {
    TabInt T;
    MakeEmpty(&T, 100);
    BacaIsi(&T);
    Sort(&T, 0);
    TulisIsiTab(T);

    return 0;
}
