/* 0～n-1中缺失的数字
   题目：一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。
   在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。
   示例1：输入: [0,1,3]
          输出: 2
   示例2：输入: [0,1,2,3,4,5,6,7,9]
          输出: 8
   限制：1 <= 数组长度 <= 10000
   分析：这题比较简单，依次输入，然后比较，遇到不等的，结束比较，并返回当前i的值。
   遇到的问题：在从键盘上输入值时，我是通过scanf（“%d”，&a[i]）返回的值来控制是否结束（正确输入（也就是输入数字）返回1，输入“回车”返回0），
   但在实际操作中，我按了回车，依旧没有结束输入，后来我写了个小程序实验了一下，发现只是起到了换行的作用，并没有参与scanf的输入判断。后来我
   在后面加了if ((ch = getchar()) == '\n')  break;，用来结束输入。
*/
#include<stdio.h>
int missingNumber(int* nums, int numSize);
int main(void) {
    int a[10000];
    int i = 0, t;
    char ch;
    while (scanf("%d", &a[i])!=0) {
        i++;
        if ((ch = getchar()) == '\n')
            break;
    }
    t = missingNumber(a, i);
    printf("%d", t);
}
int missingNumber(int* nums, int numSize) {
    int i;
    for (i = 0; i < numSize; i++)
        if (nums[i] != i)
            break;
    return i;
}
