/*  换酒问题
	题目：小区便利店正在促销，用 numExchange 个空酒瓶可以兑换一瓶新酒。你购入了 numBottles 瓶酒。如果喝掉了酒瓶中的酒，
		  那么酒瓶就会变成空的。请你计算 最多 能喝到多少瓶酒。
	示例1：
			输入：numBottles = 9, numExchange = 3
			输出：13
			解释：你可以用 3 个空酒瓶兑换 1 瓶酒。所以最多能喝到 9 + 3 + 1 = 13 瓶酒。
	示例2：
			输入：numBottles = 15, numExchange = 4
			输出：19
			解释：你可以用 4 个空酒瓶兑换 1 瓶酒。
			所以最多能喝到 15 + 3 + 1 = 19 瓶酒。
	思路：用一个while循环即可解决，条件为空瓶的剩余数量是否大于兑换新酒所需的数量，用new_numBottles记录每次兑换了几瓶新酒，
		  更新res(res+=new_numBottles)，先计算第一次兑换新酒后剩余的空酒瓶的数量，再加上新兑酒的数量，即为现在空酒瓶的数量。
*/
#include<stdio.h>
int numWaterBottles(int numBottles, int numExchange) {
	int res = numBottles, empty = numBottles, new_numBottles;
	while (empty>=numExchange) {
		new_numBottles = empty / numExchange;
		res += new_numBottles;
		empty %= numExchange;
		empty += new_numBottles;
	}
	return res;
}
int main(void) {
	int a, b;
	scanf("%d %d", &a, &b);
	int res = numWaterBottles(a, b);
	printf("%d", res);
}
