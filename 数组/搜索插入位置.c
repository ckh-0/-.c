/*  搜索插入位置
    题目：给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它
          将会被按顺序插入的位置。你可以假设数组中无重复元素。
    示例 1:
            输入: [1,3,5,6], 5
            输出: 2
    思路：主要思想是二分查找，定义一个flag=0，若找到，则flag=1，否则，flag=0；接着通过逐个比较，找到nums[i]>target的
          下标，然后返回，但要注意边界问题，当一个遍历还是没找到比target大的数字，直接返回numsSize。
*/
#include<stdio.h>
int searchInsert(int* nums, int numsSize, int target) {
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
    int i;
    if (!flag) {
        for (i = 0; i < numsSize; i++) {
            if (nums[i] > target)
                return i;
        }
        if (i == numsSize)
            return numsSize;
    }
    return 0;
}
#define SIZE 4
int main(void) {
    int nums[SIZE] = { 1,3,5,6 };
    int t = searchInsert(nums, SIZE, 2);
    printf("%d", t);
}
