/*  两个数组的交集
	题目：给定两个数组，编写一个函数来计算它们的交集。
	示例 1：
			输入：nums1 = [1,2,2,1], nums2 = [2,2]
			输出：[2]
	示例 2：
			输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
			输出：[9,4]
	说明：
			1.输出结果中的每个元素一定是唯一的。
			2.我们可以不考虑输出结果的顺序。
	思路：我创建一个新的数组res，用来记录nums1中数字出现次数，然后再遍历nums2数组，为了保证不重复，我们应加一个判断语句
		  ，if(nums2[i]==nums[i+1]) continue;再判断res[nums2[i]]>0吗，然后赋值给新的数组arr。最后你还要额外判断nums2[i]
		  是否1也是交集。
*/
#include<stdio.h>
#include<stdlib.h>
int comp(const void* _a, const void* _b) {
	int* a = (int*)_a, * b = (int*)_b;
	return *a == *b ? 0 : *a > * b ? 1 : -1;
}
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
	if (!nums1 || !nums2 || nums1Size <= 0 || nums2Size <= 0) {
		*returnSize = 0;
		return NULL;
	}
	int res[1024] = {0};
	int* arr = (int*)malloc(sizeof(int) * nums1Size);
	int i,j = 0;
	for (i = 0; i < nums1Size; i++)
		res[nums1[i]]++;
	qsort(nums2, nums2Size, sizeof(int), comp);
	for (i = 0; i < nums2Size - 1; i++) {
		if (nums2[i] == nums2[i + 1])
			continue;
		if (res[nums2[i]] > 0)
			arr[j++] = nums2[i];
	}
	if (res[nums2[nums2Size - 1]] > 0)
		arr[j++] = nums2[nums2Size - 1];
	*returnSize = j;
	return arr;
}
#define nums1Size 3
#define nums2Size 5
int main(void) {
	int nums1[nums1Size] = { 4,9,5 };
	int nums2[nums2Size] = { 9,4,9,8,4 };
	int x;
	int* returnSize = &x;
	int* q = intersection(nums1, nums1Size, nums2, nums2Size, returnSize);
	for (int i = 0; i < *returnSize; i++)
		printf("%d ", q[i]);
}
