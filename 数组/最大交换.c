/* 合并两个有序数组
   题目：给定一个非负整数，你至多可以交换一次数字中的任意两位。返回你能得到的最大值。
   示例 1 :
           输入: 2736
           输出: 7236
           解释: 交换数字2和数字7。
   示例 2 :
           输入: 9973
           输出: 9973
           解释: 不需要交换。
   注意:
        给定数字的范围是 [0, 10^8]
   思路：定义一个数组用来存储该整数的每位数，由于在数组存储每位数时，现在排序与实际排序相反，
         所以外层循环应从底数最大值开始，内层循环从0开始，依次比较，找出最低位且数字最大，再进行交换。
   总结：在开始的编程，我两个循环都是都底数大的一边开始，导致遇到两位及以上的数字相同时，无法得到最大的数字，
         在这个过程中，我尝试了很多种方法，有再加一个循环，但是都没这个简单。
*/
#include<stdio.h>
#include<math.h>
int maximumSwap(int num) {
    int nums[9],i=0,t;
    while (num!= 0) {
        nums[i++] = num % 10;
        num /= 10;
    }
    t = i-1;
    int  max = t, temp, s = 0, flag = 0,j;
    for (j = t; j >= 0; j--) {
        for (i = 0; i<j; i++) {
            if (nums[i] > nums[max]) {
                max = i;
                flag = 1;
            }
        }
         temp = nums[j];
         nums[j] = nums[max];
         nums[max] = temp;
         if (flag == 1)
            break;
          max--;
    }
    for (i = t; i >= 0; i--) {
        s += nums[i] * pow(10, t--);
    }
    return s;
}
int main() {
    int num =10909011;
    int max = maximumSwap(num);
    printf("%d", max);
}
