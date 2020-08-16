/*  最小K个数
	题目：设计一个算法，找出数组中最小的k个数。以任意顺序返回这k个数均可。
	示例：
		  输入： arr = [1,3,5,7,2,4,6,8], k = 4
		  输出： [1,2,3,4]
	提示：
		  0 <= len(arr) <= 100000
		  0 <= k <= min(100000, len(arr))
	思路：快排；
*/
#include<stdio.h>
#include<stdlib.h>
int comp(const void* _a, const void* _b) {
	int* a = (int*)_a, * b = (int*)_b;
	return *a == *b ? 0 : *a > * b ? 1 : -1;
}
int* smallestK(int* arr, int arrSize, int k, int* returnSize) {
	*returnSize = k;
	qsort(arr, arrSize, sizeof(int), comp);
	int* res = (int*)malloc(sizeof(int) * k);
	for (int i = 0; i < k; i++)
		res[i] = arr[i];
	return res;
}
#define arrSize 8
#define k 4
int main(void) {
	int arr[arrSize] = { 1,3,5,7,2,4,6,8 };
	int m = k;
	int* q = &m;
	int* p = smallestK(arr, arrSize, k, q);
	for (int i = 0; i < *q; i++)
		printf("%d ", p[i]);
}
