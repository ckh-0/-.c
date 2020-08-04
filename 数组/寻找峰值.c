/* 寻找峰值
   题目：峰值元素是指其值大于左右相邻值的元素。给定一个输入数组 nums，其中 nums[i] ≠ nums[i+1]，
		 找到峰值元素并返回其索引。数组可能包含多个峰值，在这种情况下，返回任何一个峰值所在位置即可。可以假设
		 nums[-1] = nums[n] = -∞。
   示例 1:
			输入: nums = [1,2,3,1]
			输出: 2
			解释: 3 是峰值元素，你的函数应该返回其索引 2。
   示例 2:
			输入: nums = [1,2,1,3,5,6,4]
			输出: 1 或 5 
			解释: 你的函数可以返回索引 1，其峰值元素为 2；
				  或者返回索引 5， 其峰值元素为 6。
   思路：这道题需要考虑到很多特殊条件，例如空数组，数组长度为1等等。但可以用二分法，就可以不用写这么多额外的if语句了，
         使用二分法，要想清楚当if(nums[i]>nums[i+1])时，峰值为什么一定会出先在0~i之间？我们可以考虑两种极端情况：1.当i
         前面的值都依次小于它时，那么nums[i]就是峰值。2.当i前面的值都依次大于它时，那么nums[0]就是峰值(因为题目前提条件
         假设nums[-1] = nums[n] = -∞)。
   总结：在定义的函数为int型时，结尾处一定要有返回值，哪怕是一直都用不上。
*/
#include<stdio.h>

int findPeakElement(int* nums, int numsSize) {
    if (!nums || numsSize < 1) {
        return 0;
    }
    if (numsSize == 1) {
        return 0;
    }
    if (nums[0] > nums[1]) {
        return 0;
    }
    if (nums[numsSize - 1] > nums[numsSize - 2]) {
        return numsSize - 1;
    }
    for (int i = 1; i < numsSize - 1; i++) {
        if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
            return i;
        }
    }
    return -1;
}
/*二分法
int findPeakElement(int* nums, int numsSize) {
    int left = 0, right = numsSize-1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[mid + 1]) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    return left;
}
*/
#define SIZE 7
int main(void) {
	int nums[SIZE] = { 1,2,1,3,5,6,4 };
	int t = findPeakElement(nums, SIZE);
	printf("%d", t);
}
