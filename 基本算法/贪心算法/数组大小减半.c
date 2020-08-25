/*  数组大小减半
	题目：给你一个整数数组 arr。你可以从中选出一个整数集合，并删除这些整数在数组中的每次出现。返回 至少 能删除数组中的
		  一半整数的整数集合的最小大小。
	示例 1：
			输入：arr = [3,3,3,3,5,5,5,2,2,7]
			输出：2
			解释：选择 {3,7} 使得结果数组为 [5,5,5,2,2]、长度为 5（原数组长度的一半）。大小为 2 的可行集合有 {3,5},{3,2},
				  {5,2}。选择 {2,7} 是不可行的，它的结果数组为 [3,3,3,3,5,5,5]，新数组长度大于原数组的二分之一。
	示例 2：
			输入：arr = [7,7,7,7,7,7]
			输出：1
			解释：我们只能选择集合 {7}，结果数组为空。
	提示：
			1 <= arr.length <= 10^5
			arr.length 为偶数
			1 <= arr[i] <= 10^5
	思路：定义一个数组a[100001]用来统计arr数组中数字出现的次数，然后将数组a从大到小排序，将a[i]依次累加，当和大于等于
		  arrSize/2时，跳出循环，返回count。
*/
#include<stdio.h>
#include<stdlib.h>
#define Size 10
int comp(const void* _a, const void* _b) {
	int* a = (int*)_a, * b = (int*)_b;
	return *a == *b ? 0 : *a < *b ? 1 : -1;
}
int minSetSize(int* arr, int arrSize) {
	int a[100001] = { 0 }, i, min = arrSize / 2, count = 0, s = 0;
	for (i = 0; i < arrSize; i++)
		a[arr[i]]++;
	qsort(a, 100001, sizeof(int), comp);
	for (i = 0; i < 100001; i++) {
		if (a[i] > 0) {
			count++;
			s += a[i];
		}
		if (s >= arrSize / 2)
			break;
	}
	return count;
}
int main(void) {
	int arr[Size] = { 3,3,3,3,5,5,5,2,2,7 };
	int res = minSetSize(arr, Size);
	printf("%d", res);
}
