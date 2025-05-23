#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
int main() {

    printf("Storage size for float : %ld\n", sizeof(float));
    printf("FLT_MAX  : %g\n", (float)   FLT_MAX);
    printf("FLT_MIN  : %g\n", (float)   FLT_MIN);
    printf("-FLT_MAX : %g\n", (float)  -FLT_MAX);
    printf("-FLT_MIN : %g\n", (float)  -FLT_MIN);
    printf("DBL_MAX  : %g\n", (double)  DBL_MAX);
    printf("DBL_MIN  : %g\n", (double)  DBL_MIN);
    printf("-DBL_MAX : %g\n", (double) -DBL_MAX);
    printf("Precision value : %d\n",   FLT_DIG );

    return 0;
}