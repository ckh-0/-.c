/*  去掉最低工资和最高工资后的工资平均值
	题目：给你一个整数数组 salary ，数组里每个数都是 唯一 的，其中 salary[i] 是第 i 个员工的工资。请你返回去掉最低工资
		  和最高工资以后，剩下员工工资的平均值。
	示例 1：
			输入：salary = [4000,3000,1000,2000]
			输出：2500.00000
			解释：最低工资和最高工资分别是 1000 和 4000 。
			去掉最低工资和最高工资以后的平均工资是 (2000+3000)/2= 2500
	示例 2：
			输入：salary = [1000,2000,3000]
			输出：2000.00000
			解释：最低工资和最高工资分别是 1000 和 3000 。
			去掉最低工资和最高工资以后的平均工资是 (2000)/1= 2000
	思路：快排。
*/
#include<stdio.h>
#include<stdlib.h>
int comp(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}
double average(int* salary, int salarySize) {
	qsort(salary, salarySize, sizeof(int), comp);
	double s = 0;
	for (int i = 1; i < salarySize - 1; i++)
		s += salary[i];
	return s / (salarySize - 2);
}
#define salarySize 4
int main(void) {
	int salary[salarySize] = { 4000,3000,1000,2000 };
	double ave = average(salary, salarySize);
	printf("%lf", ave);
}
