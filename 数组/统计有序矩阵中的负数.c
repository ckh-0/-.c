/* 统计有序矩阵中的负数
   题目：给你一个 m * n 的矩阵 grid，矩阵中的元素无论是按行还是按列，都以非递增顺序排列。 
		 请你统计并返回 grid 中 负数 的数目。
   示例 1：
			输入：grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
			输出：8
			解释：矩阵中共有 8 个负数。
   思路：这道题如果用两个for循环暴力求解，也是可以的，但是我想试试用二分法来写，每次通过判断中间值是否大于0，来进行
         下一步操作，但是要注意边界是否算进去了，所以我特别写了两个if语句用来判断边界为负，计算器count++；
   总结：开始的时候，我的while判断语句写的是left<rigthe,导致陷入无限循环，后来仔细的根据写的代码带入数据推导了一遍，
         发现总是在right和left相差一时，陷入死循环，故我把while循环条件改为right-left>1。
*/
#include<stdio.h>
int countNegatives(int** grid, int gridSize, int* gridColSize) {
	int count = 0,t=*gridColSize;
	if (!grid)
		return 0;
	for (int i = 0; i < gridSize; i++) {
		if (grid[i][0] < 0)
			count++;
		if (grid[i][t - 1] < 0&&t!=1)
			count++;
		int left = 0, right = t-1;
		while (right-left>1) {
			int mid = left + (right - left) / 2;
			if (grid[i][mid] >= 0)
				left = mid;
			else{
				count += (right-mid);
				right = mid;
			}
		}
	}
	return count;
}
int main(void) {
	int grid[4][4] = { 4,3,2,-1 ,3,2,1,-1 ,1,1,-1,-2 ,-1,-1,-2,-3 };
	int* p[4] = { grid[0],grid[1],grid[2],grid[3] };
	int t = 4;
	int* s=&t;
	int m=countNegatives(p, 4, s);
	printf("%d", m);
}
