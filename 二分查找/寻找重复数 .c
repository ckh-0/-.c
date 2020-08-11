/* 寻找重复数 
   题目：给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。
		 假设只有一个重复的整数，找出这个重复的数。
   示例 1:
			输入: [1,3,4,2,2]
			输出: 2
   示例 2:
			输入: [3,1,3,4,2]
			输出: 3
   说明：
		1.不能更改原数组（假设数组是只读的）。
		2.只能使用额外的 O(1) 的空间。
		3.时间复杂度小于 O(n2) 。
		4.数组中只有一个重复的数字，但它可能不止重复出现一次。
   分析：这道题感觉还挺绕的，题目描述的有点难理解。为什么是给定n+1个整数的数组nums？说明数组都是都索引0开始的，n即为
		 numsSize-1。其数字都在 1 到 n 之间（包括 1 和 n），指的是数组里面的数字大小都在1~numsSize-1之间。由此可知至少
		 存在一个重复的数。使用二分法，我们可以这样想，由于数字大小都在1~numsSize-1之间，我们可以通过和连续数列1~numsSize
		 -1的中间值比较，我们通过for循环遍历原数组，统计<=mid的元素的个数，若计算器count>mid,说明重复的数在1~mid之间，反
		 之则在mid+1~numsSize-1之间。
*/
#include<stdio.h>
int findDuplicate(int* nums, int numsSize) {
	int left = 1, right = numsSize - 1, count;
	while (left != right) {
		int mid = (left + right) / 2;
		count = 0;
		for (int i = 0; i < numsSize; i++)
			if (nums[i] <= mid)
				count++;
		if (count > mid)
			right = mid;
		else
			left = mid + 1;
	}
	return left;
}
#define SIZE 5
int main(void) {
	int nums[SIZE] = { 1,2,2,3,4};
	int t = findDuplicate(nums, SIZE);
	printf("%d", t);
}
