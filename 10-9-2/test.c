#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
int main()
{
	int a = 0;
	int total = 0;
	int i = 0;
	scanf("%d", &a);
	for (i = 0; i < 31; i++)
	{
		int  ret = pow(2, i);
		if ((ret & a) == ret)
			total++;
	}
	printf("������1�ĸ���Ϊ%d\n", total);
	return 0;
}