/*
	3 = 00000011 (In Binary)
	5 = 00000101 (In Binary)

	AND operation        OR operation        XOR operation
	  00000011             00000011            00000011
	& 00000101           | 00000101          ^ 00000101
	  ________             ________            ________
	  00000001  = 1        00000111  = 7       00000110  = 6
*/
#include <stdio.h>
int main()
{
    int d1 = 4, /* binary 100 */
        d2 = 6, /* binary 110 */
        d3;
    printf("d1=%d, d2 = %d\n", d1, d2);
    d3 = d1 & d2;
    printf("Bitwise AND  d1 & d2 = %d\n", d3);
    d3 = d1 | d2;
    printf("Bitwise OR d1 | d2 = %d\n", d3);
    d3 = d1 ^ d2;
    printf("Bitwise XOR d1 ^ d2 = %d\n", d3);
    d3 = ~d1;
    printf("Ones complement of d1 = %d\n", d3);
    d3 = d1 << 2;
    printf("Left shift by 2 bits d1 << 2 = %d\n", d3);
    d3 = d1 >> 2;
    printf("Right shift by 2 bits d1 >> 2 = %d\n", d3);
    return 0;
}