//康托展开
#include<stdio.h>
int cantor(int a[], int n);
int main()
{
	int s[] = {3,4,1,5,2};
	int t;
	t=cantor(s, sizeof(s) / 4);
	printf("%d", t);
	return 0;
}
int cantor(int a[], int n)
{
	int s = 0;
	for (int i = 0; i < n; i++)
	{
		int x = 0, c = 1, m = 1;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[i])
				x++;
			m *= c;
			c++;
		}
		s += x * m;
	}
	return s+1;
}
