/* 删除排序数组中的重复项
       给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
   不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
   示例1：给定数组 nums = [1,1,2], 函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。 
          你不需要考虑数组中超出新长度后面的元素。
   示例2：给定数组 nums = [0,0,1,1,1,2,2,3,3,4], 函数应该返回新的长度 5, 并且原数组 nums 的前5个元素被修改为 0,1,2,3,4。
          你不需要考虑数组中超出新长度后面的元素。
   思路：先使用for循环嵌套if语句寻找重复的两个数，若是找到，首先数组的长度减少1，再嵌套一个for循环，依次交换数值，
         最后不要忘记把之前的底数减1，以免碰到连续三个或以上重复数字。
         遇到的问题：1.我在第一次提交时，忘记底数减一，导致遇到三个重复的，只能消去一个。
                     2.我在第二次提交时，用的是 for (int i = 0; i < numsSize; i++) ，然后在底数减一时，导致数组越界。
*/
#include<stdio.h>
#define len 10
int removeDuplicates(int* nums, int numsSize) {
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i -1]) {
            numsSize--;
            for (int j = i ; j < numsSize; j++)
                nums[j] = nums[j + 1];
            i--;
        }
    }
    return numsSize;
}
int main(void) {
    int nums[len] = {0,0,1,1,1,2,2,3,3,4};
    int t = removeDuplicates(nums, len);
    for (int i = 0; i < t; i++)
        printf("%d ", nums[i]);
}
