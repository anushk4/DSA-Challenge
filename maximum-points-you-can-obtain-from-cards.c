// submission: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/submissions/1003000687/
// time complexity: O(n)
// logic: another way to ask to find a subarray with minimum sum

int maxScore(int* cardPoints, int cardPointsSize, int k){
        int window = cardPointsSize - k;
    int total = 0;
    for (int i = 0; i < cardPointsSize; i++){
        total += cardPoints[i];
    }
    int min_sum = 0;
    for (int i = 0; i < window; i++){
        min_sum += cardPoints[i];
    }
    int sum = min_sum;
    for (int i = 1; i < cardPointsSize - window + 1; i++){
        sum = cardPoints[i + window - 1] + sum - cardPoints[i-1];
        sum < min_sum ? min_sum = sum : printf("");
    }
    return total-min_sum;
}
