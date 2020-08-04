/* 将每个元素替换为右侧最大元素
   题目：给你一个数组 arr ，请你将每个元素用它右边最大的元素替换，如果是最后一个元素，用 -1 替换。
		 完成所有替换操作后，请你返回这个数组。
   示例：
		输入：arr = [17,18,5,4,6,1]
		输出：[18,6,6,6,1,-1]
	提示：
		 1 <= arr.length <= 10^4
		 1 <= arr[i] <= 10^5
	思路：两个for循环就可以写出来，但要注意数组不要越界。
*/
#include<stdio.h>
#include<stdlib.h>
void replaceElements(int* arr, int arrSize) {
	int i, j;
	for (i = 0; i < arrSize-1; i++) {
		int max = arr[i + 1];
		for (j = i + 1; j < arrSize; j++) {
			if (arr[j] > max)
				max = arr[j];
		}
		arr[i] = max;
	}
	arr[arrSize - 1] = -1;
}
#define SIZE 6
int main() {
	int arr[SIZE] = { 17,18,5,4,6,1 };
	replaceElements(arr, SIZE);
	for (int i = 0; i < SIZE; i++)
		printf("%d ", arr[i]);
}
