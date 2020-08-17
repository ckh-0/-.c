/*  数组的相对排序
	题目：给你两个数组，arr1 和 arr2，
			 arr2 中的元素各不相同
			 arr2 中的每个元素都出现在 arr1 中
		  对 arr1 中的元素进行排序，使 arr1 中项的相对顺序和 arr2 中的相对顺序相同。未在 arr2 中出现过的元素需要按照
		  升序放在 arr1 的末尾。
	示例：
		  输入：arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
		  输出：[2,2,2,1,4,3,3,9,6,7,19]
	提示：
		  arr1.length, arr2.length <= 1000
		  0 <= arr1[i], arr2[i] <= 1000
		  arr2 中的元素 arr2[i] 各不相同
		  arr2 中的每个元素 arr2[i] 都出现在 arr1 中
	思路：首先根据数组的长度定义一个新的数组arr[1001]，通过遍历arr1数组，记录arr1中数字出现的次数，用arr[arr1[i]]++实现。
		  再次遍历arr2数组，记录在arr1和arr2中都出现的数字，通过判断arr[arr2[i]]是否大于0，来挑选符合条件的数字。第三次
		  遍历arr数组，找出只在arr1中出现的数字，将他们按照从小到大的顺序排在后面。
	总结：这道题的思路是参考题解的，感觉这种方法很巧妙，可以学习学习。
*/
#include<stdio.h>
int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int returnSize) {
	int arr[1001] = { 0 };
	int i, j = 0;
	for (i = 0; i < arr1Size; i++)
		arr[arr1[i]]++;
	for (i = 0; i < arr2Size; i++) {
		while (arr[arr2[i]] > 0) {
			arr1[j++] = arr2[i];
			arr[arr2[i]]--;
		}
	}
	for (i = 0; i < 1001; i++) {
		while (arr[i] > 0) {
			arr1[j++] = i;
			arr[i]--;
		}
	}
	return arr1;
}
#define arr1Sive 11
#define arr2Sive 6
int main(void) {
	int arr1[arr1Sive] = { 2,3,1,3,2,4,6,7,9,2,19 };
	int arr2[arr2Sive] = { 2,1,4,3,9,6 };
	int* q = relativeSortArray(arr1, arr1Sive, arr2, arr2Sive, arr1Sive);
	for (int i = 0; i < arr1Sive; i++)
		printf("%d ", q[i]);
}
