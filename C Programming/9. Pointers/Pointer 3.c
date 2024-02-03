void swapv (int x,int y)
{
int t; t=x; x=y; y=t;
printf("x=%d\t=%d\n",x,y);
}
int main(void)
{
int a= 10,b=20;
swapv (a,b);
printf("a=%d b=%d\n",a,b);
return 0;
}
