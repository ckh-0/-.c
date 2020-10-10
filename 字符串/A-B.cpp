/* 题目：本题你计算A−B。不过麻烦的是，A和B都是字符串 —— 即从字符串A中把字符串B所包含的字符全删掉，剩下的字符组成的就是字符串A−B。
   输入格式：输入在2行中先后给出字符串A和B。两字符串的长度都不超过10^4，并且保证每个字符串都是由可见的ASCII码和空白字符组成，最后以换行符结束。
   输出格式：在一行中打印出A−B的结果字符串。
   输出样例：I love GPLT!  It's a fun game!
            aeiou
   输出样例：I lv GPLT!  It's  fn gm!
   思路：读取两个字符串A,B,调用C++的自带的字符串find和erase函数，可以很快的找到在A中出现B字符的下标，然后删除。
   总结：1.这道题输入时，需要读入空格（也就是遇空格不结束读取），这时我们要用到cin.getline()，cin.getline（）不会读入回车符，会舍弃。关于cin，
          cin.get(),cin.getline(),getline()的详细讲解，请参考https://blog.csdn.net/a3192048/article/details/80303547?utm_source=app
         2.在解决字符串的问题时，利用C++自带的字符串处理函数会非常方便，多了解库函数。
*/
#include <iostream>
#include<cstring>
using namespace std;
char str1[10000], str2[10000];
int main() {
	string A, B;
	cin.getline(str1, 1000);
	A = str1;
	cin.getline(str2, 1000);
	B = str2;
	for (int i = 0; i < B.size(); i++) {
		int t = A.find_first_of(B[i], 0);
		while (t != -1) {
			A.erase(t, 1);
			t = A.find_first_of(B[i], 0);
		}
	}
	cout << A;
}
