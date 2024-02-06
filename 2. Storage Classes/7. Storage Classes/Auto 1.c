#include<stdio.h>
int main()
{
	auto int a=1; // Block 1
	{
		auto int a=2; // Block 2
		{
			auto int a=3; // Block 3
			{
				printf("\n block 3 : %d ",a);
			}
		}
		printf("\n block 2 : %d ",a);
	}
	printf("\n block 1 : %d\n",a);
}
			