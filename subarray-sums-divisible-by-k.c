// using prefix-sum approach
// submission: https://leetcode.com/problems/subarray-sums-divisible-by-k/submissions/988693359/

int subarraysDivByK(int* nums, int numsSize, int k) {
    int count = 0;
    int sum = 0;
    int* freq = (int*)malloc(k*sizeof(int));
    memset(freq, 0, sizeof(int)*k);
    freq[0]=1;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        int remainder = (sum % k + k) % k;  // Ensure positive remainder
        count += freq[remainder];
        freq[remainder]++;
    }

    return count;
}
