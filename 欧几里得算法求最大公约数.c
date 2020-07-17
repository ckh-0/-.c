//欧几里得算法求最大公约数
#include<stdio.h>
int main()
{
	int a, b, y, r,t,m,n;
	printf("Please input two numbers:\n");
	scanf("%d %d", &a, &b);
	m = a;
	n = b;
	if (a >= b)
	{
		r = a % b;
	}
	else
	{
		t = a;
		a = b;
		b = t;
		r = a % b;
	}
	while (r)
	{
		a = b;
		b = r;
		r = a % b;
	}
	printf("%d和%d最大公约数是:%d", m, n, b);
}
