#include <stdio.h>

void main()
{
    unsigned int NTC1=3;
    unsigned int NTC2=1;
    unsigned int NTC3=6;
    unsigned int NTC=7;
    if(NTC1==NTC2 && NTC1==NTC3){NTC=NTC1;}
    else if(NTC1==NTC2 && NTC1>NTC3){NTC=NTC1;}
    else if(NTC1==NTC3 && NTC1>NTC2){NTC=NTC1;}
    else if(NTC2==NTC3 && NTC2>NTC1){NTC=NTC2;}
    //else if(NTC1==NTC2 && NTC3>NTC1){NTC=NTC3;}
    //else if(NTC1==NTC3 && NTC2>NTC1){NTC=NTC2;}
    //else if(NTC2==NTC3 && NTC1>NTC2){NTC=NTC1;}
    else if(NTC1>NTC2 && NTC1>NTC3){NTC=NTC1;}
    else if(NTC2>NTC1 && NTC2>NTC3){NTC=NTC2;}
    else if(NTC3>NTC1 && NTC3>NTC2){NTC=NTC3;}
    else {NTC=0;}
    printf("NTC=%d",NTC);
}
