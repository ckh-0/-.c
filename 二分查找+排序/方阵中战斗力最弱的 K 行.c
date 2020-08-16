/* 方阵中战斗力最弱的 K 行
   题目：给你一个大小为 m * n 的方阵 mat，方阵由若干军人和平民组成，分别用 1 和 0 表示。请你返回方阵中战斗力
         最弱的 k 行的索引，按从最弱到最强排序。如果第 i 行的军人数量少于第 j 行，或者两行军人数量相同但 i 小于
         j，那么我们认为第 i 行的战斗力比第 j 行弱。军人 总是 排在一行中的靠前位置，也就是说 1 总是出现在 0 之前。
   示例 1：
            输入：mat = 
            [[1,1,0,0,0],
            [1,1,1,1,0],
            [1,0,0,0,0],
            [1,1,0,0,0],
            [1,1,1,1,1]], 
            k = 3
            输出：[2,0,3]
            解释：
            每行中的军人数目：
            行 0 -> 2 
            行 1 -> 4 
            行 2 -> 1 
            行 3 -> 2 
            行 4 -> 5 
            从最弱到最强对这些行排序后得到 [2,0,3,1,4]
    分析：由于每行数字中的数字都是从大到小排列的，可以用二分求出每行士兵数。然后利用快排，求出士兵数最少的k行。
    总结：这道题最巧妙的地方在于对最小的数在排序后对其原来索引的保留，具体如何实现呢？先求出该行的士兵数，然后让其乘上
          总行数（只要比总行数大就行）再加上当前行索引，可以理解成是在原来的基础上扩大了一个数量级，但为了保证加的索引
          对后面排序没有影响，故要保证乘的数要比总行数大。
*/
#include<stdio.h>
#include<stdlib.h>
int comp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize) {
    int* h = (int*)malloc(sizeof(int) * matSize);
    int* t = (int*)malloc(sizeof(int) * k);
    for (int i = 0; i < matSize; i++) {
        int left = 0, right = *matColSize - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (mat[i][mid] == 1)
                left = mid + 1;
            else
                right = mid - 1;                
        }
        h[i] = left * matSize + i;
    }
    qsort(h, matSize, sizeof(int), comp);
    for (int i = 0; i < *returnSize; i++)
        t[i] = h[i] % matSize;
    return t;
}
#define k 4
#define matColSize 2
#define matSize 4
int main(void) {
    int mats[matSize][matColSize] = {1,0,1,0,1,0,1,1};
    int* mat[matSize] = { mats[0],mats[1],mats[2],mats[3] };
    int m = k, t = matColSize;
    int* q = &m;
    int* p = &t;
    int* h = kWeakestRows(mat, matSize, p, k, q);
    for (int i = 0; i < k; i++)
        printf("%d ", h[i]);
}
