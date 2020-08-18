/*  数塔问题
	题目：如图2-8所示的一个数塔，从数塔的顶层出发，在每一个结点可以选择向左走或向右走，一直走到底层，要求找出一条路径，
		  使得路径上的数值和最大。
	示例：
								8
							12		15
						3		9		6
					8		10		5		12
				16		4		18		10		9
			输入：二维数组d[n][n];
			输出：数塔的最大数值及其路径
			解释：数塔的最大数值和是：8+15+9+10+18=60。
	思路：用maxAdd[i][j]来存储从下层到当前层的值，到了maxAdd[i-1][j]先判断max[i][j]和max[i][j+1]哪个大，大的那个数字再和
		  d[i-1][j]相加。到了顶层，即maxAdd[0][0]，只用判断maxAdd[0][0]和maxAdd[0][1]哪个大，大的再和d[0][0]相加，即为所
		  求最大值maxAdd[0][0]。
	总结：这代码从头到尾看下来，不得不感慨这代码写的真好，没有一处多余，简洁明了，简单的代码中蕴含着深刻的思想，作为动态
		  规划的经典例题，值得去反复研究，希望有一天我也能写出这样的代码吧！	  
*/
#include<stdio.h>
#define n 5
int DataTorwer(int d[n][n]) {
	int maxAdd[n][n] = { 0 }, path[n][n] = { 0 };
	int i, j;
	//初始化底层决策结果
	for (j = 0; j < n; j++)
		maxAdd[n - 1][j] = d[n - 1][j];
	//进行第i层的决策
	for(i=n-2;i>=0;i--)
		for (j = 0; j <= i; j++) {
			if (maxAdd[i + 1][j] > maxAdd[i + 1][j + 1]) {
				maxAdd[i][j] = d[i][j] + maxAdd[i + 1][j];
				path[i][j] = j;
			}
			else
			{
				maxAdd[i][j] = d[i][j] + maxAdd[i + 1][j + 1];
				path[i][j] = j + 1;
			}
		}
	printf("路径为：%d", d[0][0]);
	//顶层决策时选择下一层列下标为path[0][0]的元素
	j = path[0][0];
	for (i = 1; i < n; i++) {
		printf("-->%d", d[i][j]);
		j = path[i][j];
	}
	return maxAdd[0][0];
}
int main(void) {
	int d[n][n] = { {8},{12,15},{3,9,6},{8,10,5,12},{16,4,18,10,9} };
	printf("最大数值和为：%d\n", DataTorwer(d));
	return 0;
}
