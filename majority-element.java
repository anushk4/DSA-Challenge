// submission: https://leetcode.com/problems/majority-element/submissions/1006729302/
// time complexity: O(n)

class Solution {
    public int majorityElement(int[] nums) {
        HashMap<Integer,Integer> freq = new HashMap<>();
        int size = nums.length;
        for (int i : nums) {
            if (freq.containsKey(i)){
                int f = freq.get(i);
                freq.put(i,++f);
            }else{
                freq.put(i,0);
            }
        }
        int majority_element = 0;
        for (int i : nums) {
            if (freq.get(i) >= size / 2){
                majority_element = i;
            }
        }
        return majority_element;
    }
}
