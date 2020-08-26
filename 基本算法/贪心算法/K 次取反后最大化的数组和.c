/*  K 次取反后最大化的数组和
	题目：给定一个整数数组 A，我们只能用以下方法修改该数组：我们选择某个索引 i 并将 A[i] 替换为 -A[i]，然后总共重复这个
		  过程 K 次。（我们可以多次选择同一个索引 i）以这种方式修改数组后，返回数组可能的最大和。
	示例 1：
			输入：A = [4,2,3], K = 1
			输出：5
			解释：选择索引 (1,) ，然后 A 变为 [4,-2,3]。
	示例 2：
			输入：A = [3,-1,0,2], K = 3
			输出：6
			解释：选择索引 (1, 2, 2) ，然后 A 变为 [3,1,0,2]。
	提示：
			1 <= A.length <= 10000
			1 <= K <= 10000
			-100 <= A[i] <= 100
	思路：先将数组A进行快排，然后统计A中负数的个数，用count计数，分count>=K和count<K两种情况讨论，第一种情况比较简单，将
		  K之前的数全部取反，第种情况，要注意当count=0和左边负数右边正数的情况，要去绝对值比较大小，然后再决定对哪个进行
		  取反。
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define Size 4
int comp(const void* _a, const void* _b) {
	int* a = (int*)_a, * b = (int*)_b;
	return *a == *b ? 0 : *a > * b ? 1 : -1;
}
int largestSumAfterKNegations(int* A, int ASize, int K) {
	qsort(A, ASize, sizeof(int), comp);
	int i, count = 0;
	for (i = 0; i < ASize; i++) {
		if (A[i] <= 0)
			count++;
		else
			break;
	}
	if (count >= K) {
		for (int j = 0; j < K; j++)
			A[j] = -A[j];
	}
	else
	{
		int j;
		for (j = 0; j < count; j++)
			A[j] = -A[j];
		while (K > count) {
			if (j == 0)
				A[0] = -A[0];
			else
				if (fabs(A[j - 1]) < fabs(A[j]))
					A[j - 1] = -A[j - 1];
				else
					A[j] = -A[j];
			count++;
		}
	}
	int s = 0;
	for (i = 0; i < ASize; i++)
		s += A[i];
	return s;
}
int main(void) {
	int A[Size] = { 3,-1,0,2 };
	int res = largestSumAfterKNegations(A, Size, 3);
	printf("%d", res);
}
