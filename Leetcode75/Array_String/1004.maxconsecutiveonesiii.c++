class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // Left pointer of the sliding window
        int left = 0;

        // Count of zeros in the current window
        int zeroCount = 0;

        // Iterate through the array with the right pointer (implicit)
        for (int num : nums) {
            // If current element is 0, increment zero count
            // XOR with 1 converts: 0 -> 1, 1 -> 0
            zeroCount += num ^ 1;

            // If we have more zeros than allowed flips
            if (zeroCount > k) {
                // Remove the leftmost element from window
                // If it was a zero, decrement zero count
                zeroCount -= nums[left] ^ 1;
                // Move left pointer forward
                left++;
            }
        }

        // The window size at the end is the maximum length
        // Window size = total array size - left pointer position
        return nums.size() - left;
    }
};