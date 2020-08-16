/*  两个数组的交集 II
	题目：给定两个数组，编写一个函数来计算它们的交集。
	示例 1：
			输入：nums1 = [1,2,2,1], nums2 = [2,2]
			输出：[2,2]
	示例 2:
			输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
			输出：[4,9]
	说明：
			1.输出结果中每个元素出现的次数，应与元素在两个数组中出现次数的最小值一致。
			2.我们可以不考虑输出结果的顺序。
	思路：先把两个数组进行排序，让两个数组的尾部进行比较，如此同时让两个数组的头部也进行比较，这样两端一起进行，我想
		  应该能提供程序的效率。
	总结：使用快排函数时，若数组中有相等的数时，在comp函数，return应该有*a-*b变为 *a == *b ? 0 : *a > * b ? 1 : -1。
*/
#include<stdio.h>
#include<stdlib.h>
int comp(const void* _a, const void* _b) {
	int* a = (int*)_a, * b = (int*)_b;
	return *a == *b ? 0 : *a > * b ? 1 : -1;
}
int judge(int a, int b) {
	if (a > b)
		return 1;
	else
		return 0;
}
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
	int* p;
	if(judge(nums1Size,nums2Size))
		p = (int*)malloc(sizeof(int) * nums2Size);
	else
		p = (int*)malloc(sizeof(int) * nums1Size);
	qsort(nums1, nums1Size, sizeof(int), comp);
	qsort(nums2, nums2Size, sizeof(int), comp);
	int end1 = nums1Size - 1, start1 = 0, end2 = nums2Size - 1, start2 = 0;
	int t = 0;
	while (end1>=start1&&end2>=start2) {
		if (nums1[end1] > nums2[end2])
			end1--;
		else if (nums1[end1] < nums2[end2])
			end2--;
		else {
			p[t++] = nums1[end1];
			end1--;
			end2--;
		}
		if(end1>start1&&end2>start2){
			if (nums1[start1] > nums2[start2])
				start2++;
			else if (nums1[start1] < nums2[start2])
				start1++;
			else {
				p[t++] = nums1[start1];
				start1++;
				start2++;
			}
		}
	}
	*returnSize = t;
	return p;
}
#define nums1Size 4
#define nums2Size 3
int main() {
	int nums1[nums1Size] = { -2147483648,1,2,3 };
	int nums2[nums2Size] = { 1,-2147483648,-2147483648 };
	int x;
	int* returnSize=&x;
	int* p = intersect(nums1, nums1Size, nums2, nums2Size, returnSize);
	for (int i = 0; i < *returnSize; i++)
		printf("%d ", p[i]);
}
