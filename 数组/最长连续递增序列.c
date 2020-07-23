/* 最长连续递增序列
   题目：给定一个未经排序的整数数组，找到最长且连续的的递增序列，并返回该序列的长度。
         示例 1:
            输入: [1,3,5,4,7]
            输出: 3
            解释: 最长连续递增序列是 [1,3,5], 长度为3。
            尽管 [1,3,5,7] 也是升序的子序列, 但它不是连续的，因为5和7在原数组里被4隔开。
         示例 2:
            输入: [2,2,2,2,2]
            输出: 1
            解释: 最长连续递增序列是 [2], 长度为1。
         注意：数组长度不会超过10000。
    分析：一次遍历，判断是否和后续元素发生逆序。但是需要特别注意一下为空数组时的情况。
    总结：主函数的输入函数写的还是有点瑕疵，为了能够满足可以输入空数组，导致在需要输入数据时，需要先输入一个空格。
*/
#include<stdio.h>
int findLengthOfLCIS(int* nums, int numsSize);
int main() {
    int nums[10000], t, len=0,i=0;
    char ch;
    printf("如果是输入是空数组，请直接输入回车结束;如需输入数据，请先输入一个空格：\n");
    if ((ch = getchar()) == '\n')
        t = 0;
    else
    {
        while (1)
        {
            scanf("%d", &nums[i++]);
            len++;
            if ((ch = getchar()) == '\n')
                break;
        }
        t = findLengthOfLCIS(nums, len);
    }
    printf("%d",t);
}
int findLengthOfLCIS(int* nums, int numsSize){
    int i, count = 1, max = 0;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] < nums[i + 1])
            count++;
        else {
            if (count > max)
                max = count;
            count = 1;
        }
    }
    if (count>max)
        max = count;
    return max;
}
