class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Initialize result variable to store XOR of all elements
        int result = 0;
      
        // Iterate through each number in the array
        for (int num : nums) {
            // XOR current number with result
            // XOR properties: a ^ a = 0, a ^ 0 = a
            // All duplicate numbers will cancel out, leaving only the single number
            result ^= num;
        }
      
        // Return the single number that appears only once
        return result;
    }
};
