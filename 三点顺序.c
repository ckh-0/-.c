/* 三点顺序
    分析：利用矢量叉积判断是逆时针还是顺时针。
          设A(x1,y1),B(x2,y2),C(x3,y3),则三角形两边的矢量分别是：
          AB=(x2-x1,y2-y1), AC=(x3-x1,y3-y1)
          则AB和AC的叉积为：(2*2的行列式)
              |x2-x1, y2-y1|
              |x3-x1, y3-y1|
          值为：(x2-x1)*(y3-y1) - (y2-y1)*(x3-x1)
          利用右手法则进行判断：
            如果AB*AC>0,则ABC三点是逆时针的
            如果AB*AC<0,则ABC三点是顺时针的
            如果AB*AC=0，则说明三点共线，
*/
#include<stdio.h>
int main() {
    double x1, y1, x2, y2, x3, y3, s;
    printf("输入三点坐标(二维):\n");
    scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3);
    s = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
    if (s > 0)
        printf("三点是逆时针排列！");
    if (s < 0)
        printf("三点是顺时针排列！");
    else
        printf("三点共线！");
}
