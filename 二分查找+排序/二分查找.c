/* 二分查找
   题目：给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，
         如果目标值存在返回下标，否则返回 -1。
   示例 1:
            输入: nums = [-1,0,3,5,9,12], target = 9
            输出: 4
            解释: 9 出现在 nums 中并且下标为 4
   方法：二分查找
         二分查找是一种基于比较目标值和数组中间元素的教科书式算法。
         如果目标值等于中间元素，则找到目标值。
         如果目标值较小，继续在左侧搜索。
         如果目标值较大，则继续在右侧搜索。

*/
#include<stdio.h>
int search(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1, flag = 0;
    while (left<=right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] > target)
            right = mid - 1;
        else if (nums[mid] < target)
            left = mid + 1;
        else {
            flag = 1;
            return mid;
        }
    }
    if (!flag)
        return -1;
    return 0;
}
#define SIZE 6
int main(void) {
    int nums[SIZE] = { -1,0,3,5,9,12 };
    int t = search(nums, SIZE, 9);
    printf("%d", t);
}
