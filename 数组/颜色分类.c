/* 颜色分类
   题目：给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，
         并按照红色、白色、蓝色顺序排列。此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
   注意:
       不能使用代码库中的排序函数来解决这道题。
   示例:
       输入: [2,0,2,1,1,0]
       输出: [0,0,1,1,2,2]
   思路：选择排序。
*/
#include<stdio.h>
void sortColors(int* nums, int numsSize) {
    int i, j, idex, temp;
    for (i = 0; i < numsSize - 1; i++) {
        idex = i;
        for (j = i + 1; j < numsSize; j++) {
            if (nums[idex] > nums[j])
                idex = j;
        }
        temp = nums[idex];
        nums[idex] = nums[i];
        nums[i] = temp;
    }
}
int main(void) {
    int nums[6] = { 2,0,2,1,1,0 };
    sortColors(nums, 6);
    for (int i = 0; i < 6; i++) {
        printf("%d", nums[i]);
    }
}
