/*  按奇偶排序数组 II
	题目：给定一个非负整数数组 A， A 中一半整数是奇数，一半整数是偶数。对数组进行排序，以便当 A[i] 为奇数时，i 也是奇数；当 A[i] 为偶数时， i 也是偶数。
		  你可以返回任何满足上述条件的数组作为答案。
	示例：
			输入：[4,2,5,7]
			输出：[4,5,2,7]
			解释：[4,7,2,5]，[2,5,4,7]，[2,7,4,5] 也会被接受。
	提示：
			2 <= A.length <= 20000
			A.length % 2 == 0
			0 <= A[i] <= 1000
	思路：外层for循环遍历整个数组，判断奇偶数，定义两个奇偶索引m=0,n=1,初始化一个新的数组res，若为奇数，res[n]=A[i];n+=2;
		  若为偶数，res[m]=A[i];m+=2;
*/
#include<stdio.h>
#include<stdlib.h>
int* sortArrayByparityII(int* A, int ASize, int returnSize) {
	int* res = (int*)malloc(sizeof(int) * ASize);
	int m = 0, n = 1;
	for (int i = 0; i < ASize; i++) {
		if (A[i] % 2 == 0) {
			res[m] = A[i];
			m += 2;
		}
		else {
			res[n] = A[i];
			n += 2;
		}
	}
	return res;
}
#define ASize 4
int main(void) {
	int A[ASize] = { 4,2,5,7 };
	int returnSize = ASize;
	int* q = sortArrayByparityII(A, ASize, returnSize);
	for (int i = 0; i < returnSize; i++) {
		printf("%d ", q[i]);
	}
