// submission: https://leetcode.com/problems/container-with-most-water/submissions/997913160/

int maxArea(int* height, int heightSize){
    int max_vol = 0;
    int left = 0;
    int right = heightSize - 1;
    while (left < right) {
        int width = right - left;
        int volume = fmin(height[left], height[right]) * width;
        max_vol = fmax(max_vol, volume);
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    return max_vol;
}
