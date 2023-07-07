// using hash table
// constraints: without modifying the original array and only constant extra space
// time complexity: O(n), space complexity: O(n)
// submission: https://leetcode.com/problems/find-the-duplicate-number/submissions/988650715/

int findDuplicate(int* nums, int numsSize){
    int* hash=(int*)malloc((numsSize-1)*sizeof(int));
    memset(hash,-1,(numsSize-1)*sizeof(int));
    int duplicate;
    for (int i=0;i<numsSize;i++){
        if (hash[nums[i]-1]==-1){
            hash[nums[i]-1]=nums[i];
        }else{
            duplicate=nums[i];
            break;
        }
    }
    return duplicate;
}
