/* 矩阵置零
   题目：编写一种算法，若M × N矩阵中某个元素为0，则将其所在的行与列清零。
   示例：
   输入：
		[
		  [1,1,1],
		  [1,0,1],
		  [1,1,1]
		]
   输出：
		[
		  [1,0,1],
		  [0,0,0],
		  [1,0,1]
		]
	思路：定义一个动态指针s，分配一个大小为m*n的空间，二维数组 如matrix[1][2]可看成*(*matrix+1+2),
	      依次赋值给*(s+i),后面就比较简单了。
	总结：我测试了好几组数据，都是可以的，但在leetcode提交时，显示数组越界，检查了好遍都没问题，不知道为什么。
*/
#include<stdio.h>
#include<stdlib.h>
void setZeroes(int** matrix, int matrixSize, int* materixColSize) {
	int* s = (int*)malloc(sizeof(int) * matrixSize * *materixColSize);
	for (int i = 0; i < matrixSize * *materixColSize; i++)
		*(s + i) = *(*matrix + i);
	for (int i = 0; i < matrixSize * *materixColSize; i++) {
		if (*(s + i) == 0) {
			int m = i / *materixColSize, n = i % *materixColSize;
			for (int j = m * matrixSize; j < (m * matrixSize + *materixColSize); j++)  //行置为0
				*(*matrix + j) = 0;
			for (int j = n; j <= (n + (matrixSize - 1) * *materixColSize); j += *materixColSize)    //列置为0
				*(*matrix + j) = 0;
		}
	}
	free(s);
}
#define M 3
#define N 3
int main(void) {
	int matrix[M][N] = { {1,1,1},{1,0,1},{1,1,1} };
	int* p[N] = { matrix[0],matrix[1],matrix[2] };
	int* q;
	int m = N;
	q = &m;
	setZeroes(p, M, q);
	for (int i = 0; i < M * N; i++) {
		printf("%d ", *(*matrix + i));
		if ((i + 1) % N == 0)
			printf("\n");
	}
}
