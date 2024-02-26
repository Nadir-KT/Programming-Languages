#include<stdio.h>
#include<conio.h>

struct stud
{
  int roll;
  char name[12];
  int percent;
}s = {10,"SMJC",80};

int main()
{
FILE *fp;
struct stud s1;

fp = fopen("ip.txt","w");
/* write struct s to file */
fwrite(&s, sizeof(s), 1,fp);
fclose(fp);

fp = fopen("ip.txt","r");
/* read struct s to file */
fread(&s1, sizeof(s1), 1,fp);
fclose(fp);
printf("nRoll : %d",s1.roll);
printf("nName : %s",s1.name);
printf("nPercent : %d",s1.percent);

}
