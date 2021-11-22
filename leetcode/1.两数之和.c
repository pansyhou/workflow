/*
 * @lc app=leetcode.cn id=1 lang=c
 *
 * [1] 两数之和
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    for(int i=0;i<numsSize;i++)
    {
        for (int k=i+1;k<numsSize;k++)
        {
            if (nums[i]+nums[k]==target)
            {
                int *ret=malloc((sizeof(int)*2));
                ret[0]=i,ret[1]=k;
                *returnSize=2;
                return ret;
            }
        }
    }
    *returnSize=0;
    return NULL;
}
// @lc code=end

