/* 三角形面积（海伦公式）
   海伦公式：假设在平面内，有一个三角形，边长分别为a、b、c，三角形的面积S可由以下公式求得：
             S=√p*(p-a)*(p-b)*(p-c)，p=(a+b+c)/2。
*/
#include<stdio.h>
#include<math.h>
int main() {
    double a, b, c,p,s;
    printf("Input a,b,c:\n");
    scanf("%lf %lf %lf", &a, &b, &c);
    p = (a + b + c) / 2;
    s = sqrt(p * (p - a) * (p - b) * (p - c));
    printf("三角形面积为:%.2lf", s);
}
