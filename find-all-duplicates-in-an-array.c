/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// time complexity: O(n)
// Space complexity: O(n)
// submission: https://leetcode.com/problems/find-all-duplicates-in-an-array/submissions/995312140/

int* findDuplicates(int* nums, int numsSize, int* returnSize){
    int* hash=(int*)malloc((numsSize)*sizeof(int));
    memset(hash,-1,(numsSize)*sizeof(int));
    int* duplicates = (int*)malloc(numsSize * sizeof(int));
    int j=0;
    for (int i=0;i<numsSize;i++){
        if (hash[nums[i]-1]==-1){
            hash[nums[i]-1]=nums[i];
        }else{
            duplicates[j++]=nums[i];
        }
    }
    free(hash);
    *returnSize = j;
    return duplicates;
}
