/*  多项式输出
    题目描述：一元n次多项式可用如下的表达式表示：          f (x) = anxn+ an-1xn-1 + ... + a1x + a0，a0≠0       其中，aixi 称为i 次项，ai 称为i次项的系数。
             给出一个一元多项式各项的次数和系数，请按照如下规定的格式要求输出该多项式：
             1. 多项式中自变量为x，从左到右按照次数递减顺序给出多项式。
             2. 多项式中只包含系数不为0的项。
             3. 如果多项式n次项系数为正，则多项式开头不出现“+”号，如果多项式 n 次项系数为负，则多项式以“-”号开头。
             4. 对于不是最高次的项，以“+”号或者“-”号连接此项与前一项，分别表示此项系数为正或者系数为负。紧跟一个正整数，表示此项系数的绝对值（如果一个高于0 次的项，其系数的绝对值为1，则无需
                输出1）。如果x的指数大于1，则接下来紧跟的指数部分的形式为“x^b”，其中b为x的指数；如果x的指数为1，则接下来紧跟的指数部分形式为“x”；如果x的指数为0，则仅需输出系数即可。
             5. 多项式中，多项式的开头、结尾不含多余的空格。
思路：用线性表模拟多项式的每一项，输出时，要注意上述题目所要求的条件，这道题主要麻烦就是if语句的运用。
*/
#include<iostream>
#include<cmath>
using namespace std;
typedef struct ElemType
{
	float coef;     //系数
	int expn;       //指数
	ElemType* next;
}ElemType, * Polynomial;
void CreatPolyn(Polynomial L, int m) {			//创建多项式
	Polynomial h = L;
	h->next = 0;
	for (int i = 0; i <= m; i++) {
		Polynomial p = new ElemType;
		cin >> p->coef;
		p->expn = m - i;
		p->next = 0;
		h->next = p;
		h = h->next;
	}
}
void PrintPolyn(Polynomial L) {
	Polynomial h = L;
	char op[2] = { '+','-' };
	int flag = 1;
	while (h->next)
	{
		int i = 0;
		if (h->next->coef < 0) {
			i = 1;
			flag = 0;
		}
		if (flag) {
			flag = 0;
			if (h->next->coef > 1) {
				if (h->next->expn == 0)
					cout << h->next->coef << "x";
				else if (h->next->expn == 1)
					cout << h->next->coef << "x";
				else
					cout << h->next->coef << "x^" << h->next->expn;
			}
			else if (h->next->coef == 1) {
				if (h->next->expn == 0)
					cout << "x";
				else if (h->next->expn == 1)
					cout << "x";
				else
					cout << "x^" << h->next->expn;
			}
			else
				cout << 0;
		}
		else if (h->next->coef == 0)
			;
		else if (h->next->expn == 0)
			cout << op[i] << fabs(h->next->coef);
		else if (fabs(h->next->expn) == 1 && h->next->coef == 1)
			cout << op[i] << "x";
		else if (fabs(h->next->coef) == 1)
			cout << op[i] << "x^" << h->next->expn;
		else if (h->next->expn == 1)
			cout << op[i] << fabs(h->next->coef) << "x";
		else
			cout << op[i] << fabs(h->next->coef) << "x^" << h->next->expn;
		h = h->next;
	}
}
int main() {
	Polynomial L = new ElemType;
	int m;
	cin >> m;
	CreatPolyn(L, m);
	PrintPolyn(L);
	return 0;
}
