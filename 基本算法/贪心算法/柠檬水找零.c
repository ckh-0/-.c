/*  柠檬水找零
	题目：在柠檬水摊上，每一杯柠檬水的售价为 5 美元。顾客排队购买你的产品，（按账单 bills 支付的顺序）一次购买一杯。每位
	      顾客只买一杯柠檬水，然后向你付 5 美元、10 美元或 20 美元。你必须给每个顾客正确找零，也就是说净交易是每位顾客向
		  你支付 5 美元。注意，一开始你手头没有任何零钱。如果你能给每位顾客正确找零，返回 true ，否则返回 false 。
	示例 1：
			输入：[5,5,5,10,20]
			输出：true
			解释：
			前 3 位顾客那里，我们按顺序收取 3 张 5 美元的钞票。
			第 4 位顾客那里，我们收取一张 10 美元的钞票，并返还 5 美元。
			第 5 位顾客那里，我们找还一张 10 美元的钞票和一张 5 美元的钞票。
			由于所有客户都得到了正确的找零，所以我们输出 true。
	示例 2：
			输入：[5,5,10,10,20]
			输出：false
			解释：
			前 2 位顾客那里，我们按顺序收取 2 张 5 美元的钞票。
			对于接下来的 2 位顾客，我们收取一张 10 美元的钞票，然后返还 5 美元。
			对于最后一位顾客，我们无法退回 15 美元，因为我们现在只有两张 10 美元的钞票。
			由于不是每位顾客都得到了正确的找零，所以答案是 false。
	提示：
			0 <= bills.length <= 10000
			bills[i] 不是 5 就是 10 或是 20 
	思路：主要就是看5元是否到最后还有剩余。
*/
#include<stdio.h>
#define Size 5
bool lemonadeChange(int* bills, int billsSize) {
	int  change_5, change_10, change_20, i;
	change_5 = change_10 = change_20 = 0;
	for (i = 0; i < billsSize; i++) {
		if (change_5 >= 0) {
			if (bills[i] == 5) 
				change_5++;
			else if (bills[i] == 10) {
				change_5--;
				change_10++;
			}
			else {
				if (change_10 > 0) {
					change_10--;
					change_5--;
				}
				else
					change_5 -= 3;
			}
		}
		else
			break;
	}
	if (change_5>=0)
		return true;
	else
		return false;
}
int main(void) {
	int bills[Size] = { 5,5,10,10,20 };
	bool flag = lemonadeChange(bills, Size);
	if (flag)
		printf("true");
	else
		printf("false");
}
