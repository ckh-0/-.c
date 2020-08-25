/*  最长递增子序列的个数
	题目：给定一个未排序的整数数组，找到最长递增子序列的个数.
	示例 1:
			输入: [1,3,5,4,7]
			输出: 2
			解释: 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。
	示例 2:
			输入: [2,2,2,2,2]
			输出: 5
			解释: 最长递增子序列的长度是1，并且存在5个子序列的长度为1，因此输出5。
	注意: 给定的数组长度不超过 2000 并且结果一定是32位有符号整数。
*/
#include<stdio.h>
#define Size 11
int findNumberOfLIS(int* nums, int numsSize) {
    int max = 0, i, j, cnt = 0;
    int dp[Size], count[Size];
    for (i = 0; i < numsSize; i++)
        dp[i] = 1, count[i] = 1;
    for (i = 1; i < numsSize; i++){
        for (j = 0; j < i; j++){
            if (nums[i] > nums[j]) {
                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    count[i] = count[j];
                }
                else if (dp[i] == dp[j] + 1)
                    count[i] += count[j];
                else
                    ;
            }
        }
    }
    for (i = 0; i < numsSize; i++)
        if (max < dp[i])
            max = dp[i];
    for (i = 0; i < numsSize; i++)
        if (dp[i] == max)
            cnt += count[i];
    return cnt;
}
int main(void) {
    int nums[Size] = { 100,90,80,70,60,50,60,70,80,90,100 };
	int res = findNumberOfLIS(nums, Size);
	printf("%d", res);
}
