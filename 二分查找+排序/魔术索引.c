/* 魔术索引
   题目：魔术索引。 在数组A[0...n-1]中，有所谓的魔术索引，满足条件A[i] = i。给定一个有序整数数组，编写一种方法找出魔术
         索引，若有的话，在数组A中找出一个魔术索引，如果没有，则返回-1。若有多个魔术索引，返回索引值最小的一个。
   示例1:
           输入：nums = [0, 2, 3, 4, 5]
           输出：0
           说明: 0下标的元素为0
   示例2:
           输入：nums = [1, 1, 1]
           输出：1
   分析：使用for循环进行遍历，但不是依次遍历，而是通过当前值与下标的比较进行跳跃式遍历。
*/
#include<stdio.h>
int findMagicIndex(int* nums, int numsSize) {
    int i;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] == i)
            return i;
        else if (nums[i] > i)
            i = nums[i]-1;
        else
            ;
    }
    return -1;
}
#define SIZE 5
int main(void) {
    int nums[SIZE] = { 0,2,3,4,5 };
    int t = findMagicIndex(nums, SIZE);
    printf("%d", t);
}
