/* 长度最小的子数组
   题目：给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的 连续 子数组，
         并返回其长度。如果不存在符合条件的子数组，返回 0。
   示例：
        输入：s = 7, nums = [2,3,1,2,4,3]
        输出：2
        解释：子数组 [4,3] 是该条件下的长度最小的子数组。
   思路：1.暴力法   两个for循环。
         2.双指针   定义两个指针 start 和end 分别表示子数组的开始位置和结束位置，维护变量 sum存储子数组中的元素和（即从
                    nums[start] 到nums[end] 的元素和）。初始状态下，star 和 end都指向下标 0，sum 的值为 0。每一轮迭代，
                    将 nums[end]加到sum，如果 sum≥s，则更新子数组的最小长度（此时子数组的长度是 end−start+1），然后将 
                    nums[start] 从 sum 中减去并将 start 右移，直到 sum<s，在此过程中同样更新子数组的最小长度。在每一轮
                    迭代的最后，将 end右移。

/*
int minSunArrayLen(int s, int* nums, int numsSize) {
    int i, j, count = 0, k = 0, min = numsSize, flag = 0;
    if (!nums)
        return 0;
    for (i = 0; i < numsSize; i++) {
        for (j = i; j < numsSize; j++) {
            k += nums[j];
            count++;
            if (k >= s&&count<=min) {
                min = count;
                flag = 1;
            }
        }
        k = 0;
        count = 0;
    }
    if (flag)
        return min;
    else
        return 0;
}
*/
int fmin(int ans, int s) {
    if (ans >= s)
        return s;
    return s;
}
#include <climits>
int minSunArrayLen(int s, int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }
    int ans = INT_MAX;
    int start = 0, end = 0;
    int sum = 0;
    while (end < numsSize) {
        sum += nums[end];
        while (sum >= s) {
            ans = fmin(ans, end - start + 1);
            sum -= nums[start];
            start++;
        }
        end++;
    }
    return ans == INT_MAX ? 0 : ans;
}
#include<stdio.h>
#define SIZE 6
int main(void) {
    int nums[SIZE] = { 2,3,1,2,4,3};
    int s = 7;
    int t = minSunArrayLen(s, nums, SIZE);
    printf("%d",t);
}
