/*  找到 K 个最接近的元素
	题目：给定一个排序好的数组，两个整数 k 和 x，从数组中找到最靠近 x（两数之差最小）的 k 个数。返回的结果必须要是
	      按升序排好的。如果有两个数与 x 的差值一样，优先选择数值较小的那个数。
	示例 1:
			输入: [1,2,3,4,5], k=4, x=3
			输出: [1,2,3,4]
	示例 2:
			输入: [1,2,3,4,5], k=4, x=-1
			输出: [1,2,3,4]
	说明:
			1.k 的值为正数，且总是小于给定排序数组的长度。
			2.数组不为空，且长度不超过 10^4
			3.数组里的每个元素与 x 的绝对值不超过 10^4
	思路：既然是要求与x距离最近的k个数，我们先将arr数组中每个数都先减去x，再求绝对值，然后在排序，找出绝对值最小的k个数，
		  但这时有一个问题，我们不知道该绝对值对应的原数组的数是多少，所以再第一步求绝对值时，我们需要一点小小的技巧，
		  即令q[i]=q[i] = fabs((arr[i] - x)) * arrSize + i，再求原数时，我们可以令他们的下标等于q[i] % arrSize，即p[i]
		  =arr[q[i] % arrSize]，然后再将p[i]排序。
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int comp(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}
int* findClosestElements(int* arr, int arrSize, int k, int x, int* returnSize) {
	int* p = (int*)malloc(sizeof(int) * k);
	int* q = (int*)malloc(sizeof(int) * arrSize);
	for (int i = 0; i < arrSize; i++)
		q[i] = fabs((arr[i] - x)) * arrSize + i;
	qsort(q, arrSize, sizeof(int), comp);
	for (int i = 0; i < k; i++) {
		p[i] = arr[q[i] % arrSize];
	}
	qsort(p, k, sizeof(int), comp);
	return p;
}
#define arrSize 6
#define k 4
#define x 3
int main() {
	int arr[arrSize] = {1,2,3,4,5};
	int  t = k;
	int* returnSize=&t;
	int* p = findClosestElements(arr, arrSize, k, x, returnSize);
	for (int i = 0; i < *returnSize; i++) {
		printf("%d ", p[i]);
	}
}
