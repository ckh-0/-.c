/*  将矩阵按对角线排序
	题目：给你一个 m * n 的整数矩阵 mat ，请你将同一条对角线上的元素（从左上到右下）按升序排序后，返回排好序的矩阵。
	示例 1：
			输入：[[3,3,1,1],[2,2,1,2],[1,1,1,2]]
			输出：[[1,1,1,1],[1,2,2,2],[1,2,3,3]]
	提示：
			m == mat.length
			n == mat[i].length
			1 <= m, n <= 100
			1 <= mat[i][j] <= 100
	思路：我定义了一个一维数组，用来存储每条对角线的数据，然后用qsort来进行排序，然后然把排序后的数据，再附给原二维数组。
	总结：开始写好程序后，运行很多次，左下角的结果始终是3（应该是1），很不理解，调试了很多遍，还没发现问题，最后发现是
		  p[i]=mat[m][n],写成了p[i]=mat[m][j];
*/
#include<stdio.h>
#include<stdlib.h>
int comp(const void* _a, const void* _b) {
	int* a = (int*)_a, * b = (int*)_b;
	return *a == *b ? 0 : *a > * b ? 1 : -1;
}
int** diagonalSort(int** mat, int matSize, int matColSize) {
	int* p = (int*)malloc(sizeof(int) * 100);
	int i, j, m, n;
	for (j = 0; j < matColSize; j++) {
		m = 0, n = j, i = 0;
		while (m<matSize&&n<matColSize) {
			p[i] = mat[m][n];
			i++, m++, n++;
		}
		qsort(p, i, sizeof(int), comp);
		m = 0, n = j, i = 0;
		while (m < matSize && n < matColSize) {
			mat[m][n] = p[i];
			m++, n++, i++;
		}
	}
	for (j = 1; j < matSize; j++) {
		m = j, n = 0, i = 0;
		while (m < matSize && n <matColSize) {
			p[i] = mat[m][n];
			i++, m++, n++;
		}
		qsort(p, i, sizeof(int), comp);
		m = j, n = 0, i = 0;
		while (m < matSize && n < matColSize) {
			mat[m][n] = p[i];
			m++, n++, i++;
		}
	}
	return mat;
}
#define matSize 3
#define matColSize 4
int main(void) {
	int mats[matSize][matColSize] = { {3,3,1,1},{2,2,1,2},{1,1,1,2} };
	int* mat[matSize] = { mats[0],mats[1],mats[2] };
	int** new_mat;
	new_mat= diagonalSort(mat, matSize, matColSize);
	for (int i = 0; i < matSize; i++) {
		for (int j = 0; j < matColSize; j++)
			printf("%d ", new_mat[i][j]);
		printf("\n");
	}
