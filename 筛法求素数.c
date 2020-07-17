//筛法求素数
#include<stdio.h>
int prime(int a);
int main()
{
	int a,i;
	printf("Please input a number:\n");
	scanf("%d", &a);
	printf("1~%d的素数有:\n",a);
	for (i = 1; i <= a; i++) {
		if (prime(i))
			printf("%d ", i);
	}
	return 0;
}
int prime(int a) {
	int i;
	if (a == 2||a==3)
		return 1;
	 if (a == 1)
		return 0;
	for (i = 2; i <= a / 2; i++) {
			if (a % i == 0) {
				return 0;
			}
	}
	if (i >= a / 2)
		return 1;
}
