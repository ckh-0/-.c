/* 合并两个有序数组
   题目：给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，
   使 nums1 成为一个有序数组。
   说明：1.初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
	     2.你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
   示例：输入:
              nums1 = [1,2,3,0,0,0], m = 3
              nums2 = [2,5,6],       n = 3
              输出: [1,2,2,3,5,6]
   思路：这道题思路比较简单，先用一个循环将两个数组合并，然后用冒泡排序法进行排序。
*/
#include<stdio.h>
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i, j;
    j = 0;
    for ( i = m; i < (m + n); i++)
        nums1[i] = nums2[j++];
    int idex,temp;
    for (i = 0; i < (m + n-1); i++) {
        idex = i;
        for (j = i; j < (m + n); j++)
            if (nums1[j] < nums1[idex])
                idex = j;
        temp = nums1[i];
        nums1[i] = nums1[idex];
        nums1[idex] = temp;
    }

}
int main(void) {
    int nums1[6] = { 1,2,3,0,0,0 };
    int nums2[3] = { 2,5,6 };
    merge(nums1, 6, 3, nums2, 3,3);
    for (int i = 0; i < 6; i++) {
        printf("%d", nums1[i]);
    }
}
