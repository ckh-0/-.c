/* 寻找旋转排序数组中的最小值 II
   题目：假设按照升序排序的数组在预先未知的某个点上进行了旋转。( 例如，数组 [0,1,2,4,5,6,7]  可能变为 [4,5,6,7,0,1,2] )。
         请找出其中最小的元素。注意数组中可能存在重复的元素。
   示例 1：
          输入: [1,3,5]
          输出: 1
   示例 2：
          输入: [2,2,2,0,1]
          输出: 0
   分析：二分法：让nums[mid]和nums[right]比较大小，为什么不是和nums[left]比较呢?因为num[mid]的值会始终大于nums[left]，
         当然和右边的值比较还是因为无论数组这么旋转，它始终是有两个按升序排序的部分组成的数组。当nums[mid]<nums[right]
         时，说明此时从nums[mid]到nums[right]刚好在一个部分里面；若nums[mid]>nums[right]，说明此时nums[mid]到nums[right]
         在两个部分里面，这是就需要缩小到一个部分里，通过将left向right逼近。为什么是return nums[left](也可以是nums[right])
         而不是return[mid]呢?我认为是在二分到最后时，会只剩下两个数字进行比较，而计算机做除法是偏向左边值的，也就是到最后
         nums[mid]一定是左边的那个数字，若碰到nums[mid]<nums[right]还行，若碰到nums[mid]>nums[right]就不行了，会返回右边
         那个大的值。关于rihgt--的问题，是为了防止遇到重复的数字,缩小范围，到一个部分里面。
   总结：感觉这道题代码虽然简单，但想明白还是有点麻烦的。这道题也有另外一种简单的解法，用for循环遍历1整个数组，找最小的值。
 */
#include<stdio.h>
int findMin(int* nums, int numsSize) {
    int left = 0, right = numsSize - 1,mid;
    while (left <right) {
        mid = (left + right) / 2;
        if (nums[mid] > nums[right])
            left = mid + 1;
        else if (nums[mid] < nums[right])
            right = mid;
        else
            right--;
    }
    return nums[left];
}
#define SIZE 7
int main(void) {
    int nums[SIZE] = { 4,5,6,7,0,1,2 };
    int t = findMin(nums, SIZE);
    printf("%d", t);
}
