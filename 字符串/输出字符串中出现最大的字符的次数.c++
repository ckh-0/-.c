/*  输出字符串中出现最大的字符的次数（CCPC-2020）
    题目：输入一段只含有a~z的字符串，输出字符串中出现最大的字符的次数
    思路：创建一个cou[]数组，用来对出现的字符的次数进行记录，需要用到强制类型转换int()，将字符转换为其对应的ASCII码，之后将数组cou[]从cou[97]开始排序，输出最大值。
    问题:使用qsort进行快排时，如果比较函数comp的返回值是:return *(int*)_a < * (int*)_b,那排序的结果是有问题的，并不是从大到小排列的，需要将返回值改成：
    return *a == *b ? 0 : *a < * b ? 1 : -1。
*/
#include<iostream>
using namespace std;
int comp(const void*_a,const void*_b) {
	int* a = (int*)_a, * b = (int*)_b;
	return *a == *b ? 0 : *a < * b ? 1 : -1;
	//return *(int*)_a < * (int*)_b;         //关于快排  对于直接返回 *(int*)_a < * (int*)_b，当数组中有很多个相同的数字时，排序会出错
}
int main() {
	int cou[123] = { 0 };
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		cou[(int)s[i]]++;
	}
	qsort(&cou[97], 26, sizeof(int), comp);
	cout << cou[97];
	return 0;
}
