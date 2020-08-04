/* 和为K的子数组
   题目：给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。
   示例 1 :
			输入:nums = [1,1,1], k = 2
			输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。
    说明 :
			数组的长度为 [1, 20,000]。
			数组中元素的范围是 [-1000, 1000] ，且整数 k 的范围是 [-1e7, 1e7]。
	思路：第一个for循环用来确定从数组的哪个位置开始，(例如从arr[3]开始)，第二个for循环就把arr[3]以后的数字依次相加，
	      再添加一个if语句用来判断和是否等于k，满足计数器count++，一次for循环结束，将S重新置为0。
	总结：开始在if语句里还添加了s=0;break; ， 想的是可以提前结束循环，节约时间，但这样做的话会考虑的不全面，遇到有的
	      数据会出错。
*/
#include<stdio.h>
int subarraySum(int* nums, int numsSize, int k) {
	int i, j, count = 0, s = 0;
	for (i = 0; i < numsSize; i++) {
		for (j = i; j < numsSize; j++) {
			s += nums[j];
			if (s == k) {
				count++;
			}
		}
		s = 0;
	}
	return count;
}
#define SIZE 5
int main(void) {
	int nums[SIZE] = {1,2,1,2,1 };
	int t = subarraySum(nums, SIZE, 3);
	printf("%d", t);
}
