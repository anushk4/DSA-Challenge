// move zeroes to the end of the array
// submission: https://leetcode.com/problems/move-zeroes/submissions/987151444/

void shift_to_end(int* nums, int i, int size){
    int store=nums[i];
    for (int j=i+1;j<size;j++){
        nums[i]=nums[j];
        i++;
    }
    nums[size-1]=store;
}

void moveZeroes(int* nums, int numsSize){
    int i=0;
    int count=0;
    while (i<numsSize){
        if (nums[i]==0){
            shift_to_end(nums,i,numsSize);
            count++;
        }else{
          i++;
        }
        if (i==numsSize-count){
          break;
        }
    }
}
