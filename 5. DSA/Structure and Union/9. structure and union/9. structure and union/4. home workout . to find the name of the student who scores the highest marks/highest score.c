#include<stdio.h>
#include<conio.h>
#define S 50

struct student
  {
  char name[30];
  int rollno;
  int sub[3];
  };
main()
{
int i,j,max,count,total,n,a[S],ni;
struct student st[S];

printf("Enter how many students: ");
scanf("%d",&n);

for(i=0;i<n;i++)
    {
    printf("\nEnter name and roll number for student %d : ",i);
    scanf("%s",&st[i].name);
    scanf("%d",&st[i].rollno);
    }

for(i=0;i<n;i++)
    {
    for(j=0;j<=2;j++)
        {
        printf("\nEnter marks of student %d for subject %d : ",i,j);
        scanf("%d",&st[i].sub[j]);
        }
    }
for(i=0;i<n;i++)
{
 total=0;
    for(j=0;j<3;j++)
        {
        total=total+st[i].sub[j];
        }
    printf("\nTotal marks obtained by student %s are %d",st[i].name,total);
    a[i]=total;
}

for(j=0;j<3;j++)
{
max=0;
    for(i=0;i<n;i++)
    {
    if(max<st[i].sub[j])
        {
        max = st[i].sub[j];
        ni = i;
        }
    }
printf("\nStudent %s got maximum marks = %d in Subject : %d" , st[ni].name, max, j);
}

max =0;

for(i=0;i<n;i++)
{
    if(max< a[i])
    {
    max =a[i];
    ni =i;
    }
}

printf("\n%s obtained the total highest marks.",st[ni].name);
getch();
}
