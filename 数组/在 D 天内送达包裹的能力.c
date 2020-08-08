/* 在 D 天内送达包裹的能力
   题目：传送带上的包裹必须在 D 天内从一个港口运送到另一个港口。传送带上的第 i 个包裹的重量为 weights[i]。
         每一天，我们都会按给出重量的顺序往传送带上装载包裹。我们装载的重量不会超过船的最大运载重量。返回
         能在 D 天内将传送带上的所有包裹送达的船的最低运载能力。
   示例 1：
           输入：weights = [1,2,3,4,5,6,7,8,9,10], D = 5
           输出：15
           解释：
           船舶最低载重 15 就能够在 5 天内送达所有包裹，如下所示：
           第 1 天：1, 2, 3, 4, 5
           第 2 天：6, 7
           第 3 天：8
           第 4 天：9
           第 5 天：10
           请注意，货物必须按照给定的顺序装运，因此使用载重能力为 14 的船舶并将包装分成 (2, 3, 4, 5), (1, 6, 7), 
           (8), (9), (10) 是不允许的。
    思路：首先判断找到weight[i]中最大的数字，记为m，然后在一个for循环里，s累加weights[i]，若s==m，天数计数器d++，s置为0；若s>m，计数器d++，s置为0，
          i--(因为此时由于多加了一个数字，超出了船舶的最大容纳量，故需要减一)；最后还要有一个if (d > D||(d==D&&i<weightsSize-1)) ，判断是否超出规定天数。
    总结：这道题就是在提交时遇到了点麻烦，在编译器通过的好好的，但在leetcode提交时，显示结果与预期有差别，后来改进
          了一下算法，终于是通过了。
*/
#include<stdio.h>
int shipWithinDays(int* weights, int weightsSize, int D) {
    int i, s, d;
    s = d = 0;
    int m = weights[0];
    for (i = 1; i < weightsSize; i++)
        if (weights[i] > m)
            m = weights[i];
    for (i = 0; i < weightsSize; i++) {
        s += weights[i];
        if (s == m)
            s = 0, d++;
        if (s > m)
            i--, s = 0, d++;
        if (d > D||(d==D&&i<weightsSize-1)) {
            m++;
            i = -1;
            s = d = 0;
        }
    }
    return m;
}
#define SIZE 10
int main(void) {
    int weights[SIZE] = { 1,2,3,4,5,6,7,8,9,10};
    int t = shipWithinDays(weights, SIZE, 10);
    printf("%d", t);
}
