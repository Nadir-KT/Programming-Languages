#include<stdio.h>
main()
{
	FILE *fp;
	char ch;
	int a,b,c,d,e;
	a=b=c=d=e=0;
	fp=fopen("POEM.txt","r");
	while(1)
	{
		ch=fgetc(fp);
		if(ch==EOF)
			break;
			a++;		
		if(ch=='\n')b++;
		if(ch=='\t')c++;
		if(ch=='#')d++;
		if(ch==' ')e++;
	}
	fclose(fp);
	printf("character-%d\n",a);
	printf("newline-%d\n",b);printf("tab-%d\n",c);printf("#-%d\n",d);printf("space-%d\n",e);	
	getch();
}
