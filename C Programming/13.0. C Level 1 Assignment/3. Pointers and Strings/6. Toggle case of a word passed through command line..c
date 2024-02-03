#include <stdio.h>
#include <string.h>
#include <ctype.h>
 
//function to convert into lowercase
void stringLwr(char *s){
    int len,i;
    len=strlen(s);
     
    for(i=0;i<len;i++)
        s[i]=tolower(s[i]);
}
 
//function to convert into uppercase
void stringUpr(char *s){
    int len,i;
    len=strlen(s);
     
    for(i=0;i<len;i++)
        s[i]=toupper(s[i]);
}
 
int main(int argc, char* argv[]){
     
    if(argc<3){
        printf("Less command line arguments!!!\n");
        printf("Use prg_name lower/upper \"string\"\n");
        return -1;
    }
     
    if(strcmp(argv[1],"lower")==0){
        stringLwr(argv[2]);
        printf("Lowercase string is: %s\n",argv[2]);
    }
    else if(strcmp(argv[1],"upper")==0){
        stringUpr(argv[2]);
        printf("Uppercase string is: %s\n",argv[2]);
    }   
    else{
        printf("Use either lower or upper!!!\n");
    }
 
    return 0;
}