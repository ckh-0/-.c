/* 爱吃香蕉的珂珂
   题目：珂珂喜欢吃香蕉。这里有 N 堆香蕉，第 i 堆中有 piles[i] 根香蕉。警卫已经离开了，将在 H 小时后回来。珂珂可以
		 决定她吃香蕉的速度 K （单位：根/小时）。每个小时，她将会选择一堆香蕉，从中吃掉 K 根。如果这堆香蕉少于 K 根，
		 她将吃掉这堆的所有香蕉，然后这一小时内不会再吃更多的香蕉。珂珂喜欢慢慢吃，但仍然想在警卫回来前吃掉所有的香蕉。
		 返回她可以在 H 小时内吃掉所有香蕉的最小速度 K（K 为整数）。
   示例 1：
			输入: piles = [3,6,7,11], H = 8
			输出: 4
	示例 2：
			输入: piles = [30,11,23,4,20], H = 5
			输出: 30
	示例 3：
			输入: piles = [30,11,23,4,20], H = 6
			输出: 23
	提示：
			1 <= piles.length <= 10^4
			piles.length <= H <= 10^9
			1 <= piles[i] <= 10^9
	分析：这道题思路知道一个数学函数ceil会变得很简单。首先求数组累加求和然后除以时间得到平均值minSpeed，作为最小基准，
		  初始化一个time=H，用两个循环，外层用while让其无线循环，直至找到结果，内层用for循环，遍历整个数组，和minSpeed
		  比较，即time-=ceil(piles[i]/minSpeed),若一次遍历结束，time>=0,就return minSpeed，否则 minSpeed++；直至找到符合
		  条件的minSpeed。
	总结：数学函数ceil，可以得到大于或者等于指定表达式的最小整数值。
*/
#include<stdio.h>
#include<math.h>
int minEatingSpeed(int* piles, int pilesSize, int H) {
	int i, minSpeed, time = H;
	double s = 0;
	for (i = 1; i < pilesSize; i++)
		s += piles[i];
	minSpeed = s / time;
	while (1) {
		for (i = 0; i < pilesSize; i++) {
			time -= ceil(piles[i]*1.0/minSpeed);
		}
		if (time >= 0)
			return minSpeed;
		else
			minSpeed++;
		time = H;
	}
	return 0;
}
#define SIZE 5
int main(void) {
	int piles[SIZE] = { 30,11,23,4,20 };
	int result = minEatingSpeed(piles, SIZE, 6);
	printf("%d ", result);
}
