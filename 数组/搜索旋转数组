/* 搜索旋转数组
   题目：搜索旋转数组。给定一个排序后的数组，包含n个整数，但这个数组已被旋转过很多次了，次数不详。请编写代码
		 找出数组中的某个元素，假设数组元素原先是按升序排列的。若有多个相同元素，返回索引值最小的一个。
   示例1:
		  输入: arr = [15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14], target = 5
		  输出: 8（元素5在该数组中的索引）
   示例2:
		  输入：arr = [15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14], target = 11
		  输出：-1 （没有找到）
	提示:
		  1.arr 长度范围在[1, 1000000]之间
	分析：由于数组长度比较大，所以我想着用二分查找法去试试。首先通过for循环找到（既小于左边又小于右边的点），然后用
		  两个二分查找，依次去在这两部分去找目标数字。但要注意碰到有相同元素时，要返回最小索引，所以我在找到目标点时，
		  有加了一个while循环，用来寻找最小索引。
	总结：这道题用二分就让简单问题复杂化了，相反直接用一个for循环去遍历整个数组要简单的多，而且用时也差不多。所以，对于
		  某个问题，找到适合的方法去解题是非常重要的。
*/
#include<stdio.h>
int search(int* arr, int arrSize, int target) {
	int i,flag=0,mid;
	for (i = 0; i < arrSize; i++)
		if (arr[i] > arr[i + 1])
			break;
	int left = 0, right = i;
	while (left <= right) {
		mid = (left + right) / 2;
		if (arr[mid] > target)
			right = mid - 1;
		else if (arr[mid] < target)
			left = mid + 1;
		else {
			flag = 1;
			while (left < mid) {
				if (arr[left] == target)
					break;
				left++;
			}
			return left;
		}	
	}
	left = i + 1, right = arrSize - 1;
	while (left <= right) {
		mid = (left + right) / 2;
		if (arr[mid] > target)
			right = mid-1;
		else if (arr[mid] < target)
			left = mid + 1;
		else {
			flag = 1;
			while (left <mid) {
				if (arr[left] == target)
					break;
				left++;
			}
			return left;
		}
	}
	if (!flag)
		return -1;
	return 0;
}
#define SIZE 12
int main() {
	int arr[SIZE] = {5,5,5,1,2,3,4,5};
	int t = search(arr, SIZE, 5);
	printf("%d", t);
}
