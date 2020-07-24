/* 递减元素使数组呈锯齿状
   给你一个整数数组 nums，每次操作会从中选择一个元素并将该元素的值减少 1。
   如果符合下列情况之一，则数组A就是锯齿数组：
	    每个偶数索引对应的元素都大于相邻的元素，即 A[0] > A[1] < A[2] > A[3] < A[4] > ...
	    或者，每个奇数索引对应的元素都大于相邻的元素，即 A[0] < A[1] > A[2] < A[3] > A[4] < ...
   返回将数组 nums 转换为锯齿数组所需的最小操作次数。
   示例 1：
          输入：nums = [1,2,3]
          输出：2
          解释：我们可以把 2 递减到 0，或把 3 递减到 1。
   示例 2：
          输入：nums = [9,6,1,6,2]
          输出：4
   提示：
          1 <= nums.length <= 1000
          1 <= nums[i] <= 1000
   思路：分奇偶数讨论，要注意数组的越界问题，讨论奇数索引大的情况时，注意第一个数要单论讨论。
   总结：代码前前后后修改了很多次，考虑的不够全面，不够最后提交成功时，还是很开心的！
*/
#include<stdio.h>
int movesToMakeZigazga(int* nums, int numsSize) {
    int i, count1 = 0, count2 = 0, min, t=0;
    // 偶数索引数大的情况 ，减奇数索引的数
    for (i = 1; i < numsSize; i+=2) {    
        if (nums[i] >= nums[i - 1]) {
            t = nums[i] - nums[i - 1] + 1;
            count1 += t;
        }
        else
            t = 0;
        if (i == numsSize-1)
            break;
        else
        {
            if (nums[i]-t >= nums[i + 1]) {
                t = nums[i]- t- nums[i + 1] + 1;
                count1 += t;
            }
        }
    }
    min = count1;
    // 奇数索引数大的情况 ，减偶数索引的数
    if (nums[0]> nums[1]) {
        t = nums[0] - nums[1] + 1;
        count2 += t;
    }
    t = 0;
    for (i = 2; i < numsSize; i += 2) {
        if (nums[i] >= nums[i - 1]) {
            t = nums[i] - nums[i - 1] + 1;
            count2 += t;
        }
        else
            t = 0;
        if (i == numsSize-1)
            break;
        else
        {
            if (nums[i]-t >= nums[i + 1]) {
                t = nums[i]-t- nums[i+1] + 1;
                count2 += t;
            }
        }
    }
    if (count2 < min)
        min = count2;
    return min;
}
int main() {
    int nums[8] = {10,4,4,10,10,6,2,3};
    int t=movesToMakeZigazga(nums, 8);
    printf("%d", t);
}
