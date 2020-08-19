/*  最大子串和问题
	题目：输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。/要求时间复杂度为O(n)。
	示例1:
			输入: nums = [-2,1,-3,4,-1,2,1,-5,4]
			输出: 6
			解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
	提示：
			1 <= arr.length <= 10^5
			-100 <= arr[i] <= 100
	思路：状态定义：设动态规划数组numsAdd[i]存储以元素nums[i]为结尾的连续子数组最大和
		  转移方程：若numsAdd[i-1]<=0，说明numsAdd[i-1]对numsAdd[i]产生负贡献，即numsAdd[i-1]+nums[i]还不如nums[i]本身大。
		  初始状态：numsAdd[0]=nums[0]
		  由于numsAdd[i] 只与numsAdd[i−1] 和nums[i] 有关系，因此可以将原数组nums 用作numsAdd 列表，即直接在 nums 上修改即可.
	总结：刚开始接触动态规划，转移方程不是那么好早，看来还需要更多的练习。
*/
#include<stdio.h>
int maxSubArray(int* nums, int numsSize) {
	int i, nums_Max;
	nums_Max = nums[0];
	for (i = 1; i < numsSize; i++) {
		if (nums[i - 1] <= 0)
			nums[i] = nums[i];
		else
			nums[i] = nums[i - 1] + nums[i];
		if (nums[i] > nums_Max)
			nums_Max = nums[i];
	}
	return nums_Max;
}
#define numsSize 9
int main(void) {
	int nums[numsSize] = { -2,1,-3,4,-1,2,1,-5,4 };
	int res = maxSubArray(nums, numsSize);
	printf("%d", res);
}
