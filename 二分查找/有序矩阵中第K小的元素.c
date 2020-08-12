/* 有序矩阵中第K小的元素
   题目：给定一个 n x n 矩阵，其中每行和每列元素均按升序排序，找到矩阵中第 k 小的元素。请注意，它是排序后的第 k 
		 小元素，而不是第 k 个不同的元素。
   示例：
		matrix = [
		   [ 1,  5,  9],
		   [10, 11, 13],
		   [12, 13, 15]
		],
		k = 8,
		返回 13。
	分析：化而为数组为一维数组，初始化一个空间为matrixSize * matrixColSize的数组q，指向二维数组，再用快排，最后返回第k
		  小的值。
*/
#include<stdio.h>
#include<stdlib.h>
int comp(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}
int kthSmallest(int** matrix, int matrixSize, int matrixColSize, int k) {
	int t = matrixSize * matrixColSize;
	int* p = (int*)malloc(sizeof(int) * t);
	int* q = *matrix;
	qsort(q, t, sizeof(int), comp);
	return q[k-1];
}
#define matrixSize 3
#define matrixColSize 3
int main() {
	int matrixs[matrixSize][matrixColSize] = { {1,5,9},{10,11,13},{12,13,15} };
	int* matrix[matrixSize] = { matrixs[0],matrixs[1],matrixs[2] };
	int t = kthSmallest(matrix, matrixSize, matrixColSize, 8);
	printf("%d", t);
}
