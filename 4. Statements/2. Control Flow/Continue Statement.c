#include<stdio.h>
#include<conio.h>
int main()
{
    enum Day{Monday,Tuesday,Wednesday,Thursday,Friday,Saturday,Sunday};
    for(enum Day day = Tuesday;day<=Sunday;day++)
    {
        if(day == Wednesday)
        continue;
        printf("It's not Wednesday!\n"); //Do something useful with the day
    }
    getch();
}
