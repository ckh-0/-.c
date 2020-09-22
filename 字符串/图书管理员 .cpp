/*  图书管理员 
    题目：图书馆中每本书都有一个图书编码，可以用于快速检索图书，这个图书编码是一个正整数。每位借书的读者手中有一个需求码，这个需求码也是一个正整数。如果一本书的图书编码恰好以读者
         的需求码结尾，那么这本书就是这位读者所需要的。小 D 刚刚当上图书馆的管理员，她知道图书馆里所有书的图书编码，她请你帮她写一个程序，对于每一位读者，求出他所需要的书中图书编
         码最小的那本书，如果没有他需要的书，请输出-1
    输入描述:
         输入的第一行，包含两个正整数 n 和 q，以一个空格分开，分别代表图书馆里书的数量和读者的数量。接下来的 n 行，每行包含一个正整数，代表图书馆里某本书的图书编码。接下来的 q 行，
         每行包含两个正整数，以一个空格分开，第一个正整数代表图书馆里读者的需求码的长度，第二个正整数代表读者的需求码。
    输出描述:
         输出有 q 行，每行包含一个整数，如果存在第 i 个读者所需要的书，则在第 i 行输出第 i 个读者所需要的书中图书编码最小的那本书的图书编码，否则输出-1。
    示例1：
    输入：                             输出：
          5 5                               23
          2123                              1123
          1123                              -1                 
          23                                -1
          24                                -1
          24                                  
          2 23
          3 123
          3 124
          2 12
          2 12
     思路：创建顺序表p用来存储读者的需求码的长度和需求码，然后将p.no按从小到大进行排序，用暴力循环求解，解的条件是(Bno[j] - p[i].no) % pow(10, p[i].PnoLength) == 0，Bno是存储图书码的数组。
*/
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
struct Pno {
	int PnoLength;
	int no;
};
int comp(const void* _a, const void* _b) {
	int* a = (int*)_a, * b = (int*)_b;
	return *a == *b ? 0 : *a > * b ? 1 : -1;
}
int main() {
	int Bno[1001] = { 0 };
	Pno* p = new Pno[1001];
	int n, q;
	cin >> n >> q ;
	for (int i = 0; i < n; i++) {
		cin >> Bno[i];
	}
	qsort(Bno, n, sizeof(int), comp);
	for (int i = 0; i < q; i++) {
		cin >> p[i].PnoLength >> p[i].no;
	}
	for (int i = 0; i < q; i++) {
		int flag = 0;
		for (int j = 0; j < n; j++) {
			int t = pow(10, p[i].PnoLength);
			if ((Bno[j] - p[i].no) % t == 0) {
				cout << Bno[j]<<endl;
				flag = 1;
				break;
			}
		}
		if(!flag)
			cout << -1<<endl;
	}
    return 0;
}
