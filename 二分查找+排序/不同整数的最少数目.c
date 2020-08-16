/*  不同整数的最少数目
	题目：给你一个整数数组 arr 和一个整数 k 。现需要从数组中恰好移除 k 个元素，请找出移除后数组中不同整数的最少数目。
	示例 1：
			输入：arr = [5,5,4], k = 1
			输出：1
			解释：移除 1 个 4 ，数组中只剩下 5 一种整数。
	示例 2：
			输入：arr = [4,3,1,1,3,3,2], k = 3
			输出：2
			解释：先移除 4、2 ，然后再移除两个 1 中的任意 1 个或者三个 3 中的任意 1 个，最后剩下 1 和 3 两种整数。
	提示：
			1 <= arr.length <= 10^5
			1 <= arr[i] <= 10^9
			0 <= k <= arr.length
	思路：两次排序。
	      第一步：先对原始的数组进行排序，qsort排序后计算这n个数字出现的次数a[0],a[1],...,a[index-1]
		  第二步：对次数数组a[index]进行升序排序
		  第三步：计算结果。满足a[0] + a[1] + ... + a[i] >= k的最小i。返回index - i ，相当于移除了出现次数最小的那部分数字。
*/
#include<stdio.h>
#include<stdlib.h>
#define Max_length 100001
int comp(const void* _a, const void* _b) {
	int* a = (int*)_a, * b = (int*)_b;
	return *a == *b ? 0 : *a > * b ? 1 : -1;
}
int findLeastNumOfUniqueInts(int* arr, int arrSize, int k) {
	qsort(arr,arrSize,sizeof(int),comp);
	int index = 0,number=arr[0];
	int a[Max_length] = { 0 };
	if ((arr == NULL) || (arrSize == 0))
		return 0;
	for (int i = 0; i < arrSize; i++) {
		if (arr[i] == number) {
			a[index]++;
			continue;
		}
		index++;
		a[index]++;
		number = arr[i];
	}
	index++;
	if (k == 0)
		return index;
	int sum = k, res = index;
	qsort(a, index, sizeof(int), comp);
	for (int i = 0; i < index; i++) {
		if (a[i] < sum) {
			sum -= a[i];
			res--;
		}
		else if (a[i] == sum) {
			res--;
			return res;
		}
		else
			return res;
	}
	return res;
}
#define arrSize 3
#define k 3
int main(void) {
	int arr[arrSize] = { 1,2,3 };
	int least = findLeastNumOfUniqueInts(arr, arrSize, k);
	printf("%d", least);
}
