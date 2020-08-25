/*  最长上升子序列
	题目：给定一个无序的整数数组，找到其中最长上升子序列的长度。
	示例:
			输入: [10,9,2,5,3,7,101,18]
			输出: 4
			解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4
    思路:建立一个dp[i]数组，全部初始化为1，用来存储当前下标i最大的递增数组的长度，由于我们是通过当前nums[i]和nums[0]丶nums[1]……nums[i-1]，
         进行比较，如果大于，则dp[i]++，但要注意，当假设当遍历到j=3时，nums[i]>nums[3],有nums[i]>nums[2]>nums[1]>nums[0]，但nums[3]<nums[2],
         这是是不能进行dp[i]++的，那应该怎么防止这种情况的发生呢？我们可以在添加一条判断语句，即dp[i]<dp[j]+1。因为dp[j]是
         记录了当前下标为j的递增最大长度，我们只有保证在遍历到i时，dp[i]=dp[j]+1中，dp[j]是最大的，才能保证dp[i]是最大的。
*/
#include<stdio.h>
#define Size 8
int lengthOfLIS(int* nums, int numsSize) {
    if (numsSize == 0)
        return 0;
    int max = 1, i, j;
    int dp[Size];
    for (i = 0; i < numsSize; i++)
        dp[i] = 1;
    for (i = 1; i < numsSize; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (nums[i] > nums[j] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
                if (dp[i] > max)
                    max = dp[i];
            }
        }
    }
    return max;
}
int main(void) {
    int nums[Size] = { 10,9,2,5,3,7,101,18 };
    int res = lengthOfLIS(nums, Size);
    printf("%d", res);
}
