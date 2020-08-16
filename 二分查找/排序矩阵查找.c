/*  排序矩阵查找
	题目：给定M×N矩阵，每一行、每一列都按升序排列，请编写代码找出某元素。
	示例：
			现有矩阵 matrix 如下：
			  [
				[1,   4,  7, 11, 15],
				[2,   5,  8, 12, 19],
				[3,   6,  9, 16, 22],
				[10, 13, 14, 17, 24],
				[18, 21, 23, 26, 30]
			  ]
			给定 target = 5，返回 true。
			给定 target = 20，返回 false。
	思路：分治+二分。
*/
#include<stdio.h>
bool searchMatrix(int** matrix, int matrixSize, int matrixColSize, int target) {
	for (int i = 0; i < matrixSize; i++) {
		int left = 0, right = matrixColSize - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (matrix[i][mid] > target)
				right = mid - 1;
			else if (matrix[i][mid] < target)
				left = mid + 1;
			else
				return true;
		}
	}
	return false;
}
#define matrixSize 5
#define matrixColSize 5
#define targets 5
int main(void) {
	int matrixs[matrixSize][matrixColSize] = { {1, 4, 7, 11, 15},{2, 5,  8, 12, 19},{3,   6,  9, 16, 22},{10, 13, 14, 17, 24},{18, 21, 23, 26, 30} };
	int* matrix[matrixSize] = { matrixs[0] ,matrixs[1],matrixs[2],matrixs[3] ,matrixs[4] };
	bool flag = searchMatrix(matrix, matrixSize, matrixColSize, targets);
	if (flag)
		printf("true");
	else
		printf("false");
}
