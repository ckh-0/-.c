/*  部分排序
	题目：给定一个整数数组，编写一个函数，找出索引m和n，只要将索引区间[m,n]的元素排好序，整个数组就是有序的。注意：
	      n-m尽量最小，也就是说，找出符合条件的最短序列。函数返回值为[m,n]，若不存在这样的m和n（例如整个数组是有序的），
		  请返回[-1,-1]。
	示例：
			输入： [1,2,4,7,10,11,7,12,6,7,16,18,19]
			输出： [3,9]
	提示：
			0 <= len(array) <= 1000000
	思路：创建一个与原数组一样数值的数组arr，然后将arr排序，分别从前后遍历，找寻arr[i]和array[i]不相等时的下标，即为结果。
*/
#include<stdio.h>
#include<stdlib.h>
int comp(const void *_a, const void* _b) {
	int* a = (int*)_a, * b = (int*)_b;
	return *a == *b ? 0 : *a > * b ? 1 : -1;
}
int* subSort(int* array, int arraySize, int* returnSize) {
	int* arr = (int*)malloc(sizeof(int) * arraySize);
	int* res = (int*)malloc(sizeof(int) * 2);
	int num = 0;
	for (int i = 0; i < arraySize; i++)
		arr[i] = array[i];
	qsort(arr, arraySize, sizeof(int), comp);
	for (int i = 0; i < arraySize; i++)
		if (arr[i] != array[i]) {
			res[num++] = i;
			break;
		}
	for(int i=arraySize-1;i>=0;i--)
		if (arr[i] != array[i]) {
			res[num] = i;
			break;
		}
	if (num == 1)
		;
	else 
		res[0] = -1, res[1] = -1;
	*returnSize = 2;
	free(arr);
	return res;
}
#define arraySize 13
int main(void) {
	int array[arraySize] = { 1,2,4,7,10,11,7,12,6,7,16,18,19 };
	int x;
	int* returnSize = &x;
	int* p = subSort(array, arraySize, returnSize);
	for (int i = 0; i < *returnSize; i++) {
		printf("%d ", p[i]);
	}
	return 0;
}
