/* 同余定理
    数论中的重要概念。给定一个正整数m，如果两个整数a和b满足a-b能够被m整除，即(a-b)/m得到一个整数，
    那么就称整数a与b对模m同余，记作a≡b(mod m)。对模m同余是整数的一个等价关系。
    定义：设m是大于1的正整数，a、b是整数，如果m|(a-b)，则称a与b关于模m同余，记作a≡b(mod m)，
          读作a与b对模m同余。显然,有如下事实
         （1）若a≡0(mod m)，则m|a；
         （2）a≡b(mod m)等价于a与b分别用m去除，余数相同。
*/
#include<stdio.h>
int main(void)
{
    int a, b, m;
    printf("Input a,b,m(m>1):\n");
    scanf("%d%d%d", &a, &b, &m);
    if ((a - b) % m == 0)
        printf("%d与%d对模%d同余！\n", a, b, m);
    else
        printf("%d与%d对模%d不同余！\n", a, b, m);
}
