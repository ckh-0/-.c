/*  分发糖果
	题目：老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。你需要按照以下要求，
		  帮助老师给这些孩子分发糖果：
			每个孩子至少分配到 1 个糖果。
			相邻的孩子中，评分高的孩子必须获得更多的糖果。
		  那么这样下来，老师至少需要准备多少颗糖果呢？
	示例 1:
			输入: [1,0,2]
			输出: 5
			解释: 你可以分别给这三个孩子分发 2、1、2 颗糖果。
	示例 2:
			输入: [1,2,2]
			输出: 4
			解释: 你可以分别给这三个孩子分发 1、2、1 颗糖果。
				 第三个孩子只得到 1 颗糖果，这已满足上述两个条件。
*/
#include<stdio.h>
#define Size 100
int candy(int* ratings, int ratingsSize){
    int candy_num[ratingsSize], res = 0;
    candy_num[0] = 1;
    for(int i = 1; i < ratingsSize; i++)
        if(ratings[i] > ratings[i - 1])
            candy_num[i] = candy_num[i-1] + 1;
        else
            candy_num[i] = 1;

    for(int j = ratingsSize - 2; j >= 0; j--)
        if(ratings[j] > ratings[j + 1])
            if(candy_num[j] <= candy_num[j+1])
                candy_num[j] = candy_num[j+1] + 1;

    for(int i = 0; i < ratingsSize; i++)
        res += candy_num[i];
    return res;
}
int main() {
	int ratings[Size] = { 58,21,72,77,48,9,38,71,68,77,82,47,25,94,89,54,26,54,54,99,64,71,76,63,81,82,60,64,29,51,87,87,72,12,16,20,21,54,43,41,83,77,41,61,72,82,15,50,36,69,49,53,92,77,16,73,12,28,37,41,79,25,80,3,37,48,23,10,55,19,51,38,96,92,99,68,75,14,18,63,35,19,68,28,49,36,53,61,64,91,2,43,68,34,46,57,82,22,67,89};
	int res = candy(ratings, Size);
	printf("%d", res);
}
