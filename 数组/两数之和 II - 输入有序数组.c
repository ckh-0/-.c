/* 两数之和 II - 输入有序数组
   题目：给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。函数应该返回这两个
         下标值 index1 和 index2，其中 index1 必须小于 index2。
   说明:
        返回的下标值（index1 和 index2）不是从零开始的。
        你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
   示例:
        输入: numbers = [2, 7, 11, 15], target = 9
        输出: [1,2]
        解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。
   思路：这道题可以用双指针。定义两个指针start=0，end=numberSize-1,令sum=numbers[start]+numbers[end],由于数组是从小
         到大排列，判断sum和target的值，若sum大于target，end--，若sum小于target，start++，若相等，直接返回值。
   总结：用双指针处理问题，比直接用两个for循环来的要快的多，以后可以经常使用。
*/
#include<stdio.h>
#include<stdlib.h>
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int start = 0, end = numbersSize-1;
    *returnSize = 2;
    int* ans = (int*)malloc(sizeof(int) * 2);
    while (start<end)
    {
        int sum = numbers[start] + numbers[end];
        if (sum > target)
            end--;
        else if (sum < target)
            start++;
        else {
            ans[0] = start+1;
            ans[1] = end+1;
            return ans;
        }
    }
    return ans;
}
#define SIZE 4
int main() {
    int numbers[SIZE] = { 2,7,11,15 };
    int* s = (int*)malloc(sizeof(int) * 2);
    int p;
    int* returnSize=&p;
    s = twoSum(numbers, SIZE, 9, returnSize);
    for (int i = 0; i < *returnSize; i++)
        printf("%d ", s[i]);
}
