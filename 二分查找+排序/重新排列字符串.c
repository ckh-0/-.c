/*  重新排列字符串
	题目：给你一个字符串 s 和一个 长度相同 的整数数组 indices 。请你重新排列字符串 s ，其中第 i 个字符需要移动到 
		  indices[i] 指示的位置。返回重新排列后的字符串。
	示例1：
			输入：s = "codeleet", indices = [4,5,6,7,0,2,1,3]
			输出："leetcode"
	示例2：
			输入：s = "abc", indices = [0,1,2]
			输出："abc"
	思路：创建一个新字符串 res 来存储答案。对于s每个下标 i，将 res[indices[i]]处的字符设成s[i] 即可。
*/
#include<stdio.h>
#include<stdlib.h>
char* restoreString(char* s, int* indices, int indicesSize) {
	char* res = (char*)malloc(sizeof(char) * (indicesSize+1));
	for (int i = 0; i < indicesSize; i++) {
		res[indices[i]] = s[i];
	}
	res[indicesSize] = '\0';
	return res;
}
#define indicesSize 8
int main() {
	char s[] = "codeleet";
	int indices[indicesSize] = { 4,5,6,7,0,2,1,3 };
	char* newwords = restoreString(s, indices, indicesSize);
	printf("%s", newwords);
}
