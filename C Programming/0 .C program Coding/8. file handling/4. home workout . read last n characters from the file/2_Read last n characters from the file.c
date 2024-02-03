#include<stdio.h>
int main()
{
FILE *fp;
char ch;
int n;
long len;
printf("Enter the value of n : ");
scanf("%d",&n);
fp=fopen("a.txt","r");
if(fp==NULL)
    {
    puts("cannot open this file");
    exit(1);
    }

fseek(fp,0,SEEK_END);

len = ftell(fp);

fseek(fp,(len-n),SEEK_SET);

do {
  ch = fgetc(fp);
  putchar(ch);
}while(ch!=EOF);

fclose(fp);
getch();
}
