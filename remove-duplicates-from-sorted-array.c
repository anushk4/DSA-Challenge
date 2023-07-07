// time complexity: O(n) ; space complexity: O(n)

int removeDuplicates(int* nums, int numsSize){
    int* tmp = (int*)malloc(numsSize*sizeof(int));
    tmp[0]=nums[0];
    int i=1;
    int k=numsSize;
    for (int j=1;j<numsSize;j++){
        if (nums[j]!=nums[j-1]){
            tmp[i]=nums[j];
            i++;
        }else{
            k--;
        }
    }
    numsSize=k;
    for (int i=0;i<numsSize;i++){
        nums[i]=tmp[i];
    }
    return numsSize;
}
