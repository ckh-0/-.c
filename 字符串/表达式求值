/*  表达式求值
	题目描述：给定一个只包含加法和乘法的算术表达式，请你编程计算表达式的值。
	输入描述:
			  输入仅有一行，为需要你计算的表达式，表达式中只包含数字、加法运算符“+”和乘法运算符“*”，
			  且没有括号。所有参与运算的数字均为 0 到 231-1 之间的整数。输入数据保证这一行只有0~9、+、*
			  这12种字符。
	输出描述:
			  输出只有一行，包含一个整数，表示这个表达式的值。注意：当答案长度多于4位时，请只输出最后4位，
			  前导0不输出
	示例1
			输入：1+1*3+4
			输出：8
			说明：计算的结果为8，直接输出8。

	示例2   输入：1+1234567890*1
			输出：7891
			说明：计算的结果为1234567891，输出后4位，即7891。

	示例3	输入：1+1000000003*1
			输出：4
			说明：计算的结果为1000000004，输出后4位，即4。
  思路：用两个栈，一个存储运算符，一个存储数据，定义Sum=0，然后遍历两个栈，遇到‘*’，就从数据栈中上层两个元素并删除，作乘法运算，然后再将积放回数据栈，遇到‘+’，Sum+=数据栈的顶层元素，运算符栈为
        空后，最后记得判断数据栈是否为空，不为空，Sum+=数据栈的顶层元素。
*/
#include<iostream>
#include<stack>
using namespace std;
#define mod 10000
int PLength(int a) {
    int count=0;
    while (a != 0) {
        a /= 10;
        count++;
    }
    return count;
}
 
int main() {
    stack<char>OPTR;          //运算符栈
    stack<long long>OPND;     //运算数栈
    char s[100001];
    cin >> s;
    int Sum = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '+' || s[i] == '*')
            OPTR.push(s[i]);
        else {
            int count = PLength(atoi(s + i));
            OPND.push(atoi(s + i));
            i += count - 1;
            if (count == 0)
                i += 1;
        }
    }
    while (!OPTR.empty()) {
        if (OPTR.top() == '+') {
            Sum += OPND.top();
            OPND.pop();
        }
        else if (OPTR.top() == '*') {
            long long a = OPND.top();
            OPND.pop();
            long long b = OPND.top();
            OPND.pop();
            OPND.push(a * b);
        }
        OPTR.pop();
    }
    if (!OPND.empty())
        Sum += OPND.top() ;
    cout << Sum%mod;
    return 0;
}
