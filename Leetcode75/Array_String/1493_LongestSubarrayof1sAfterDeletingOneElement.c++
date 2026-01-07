class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int arraySize = nums.size();
      
        // leftOnes[i] stores the count of consecutive 1s ending at position i-1
        vector<int> leftOnes(arraySize + 1, 0);
      
        // rightOnes[i] stores the count of consecutive 1s starting at position i
        vector<int> rightOnes(arraySize + 1, 0);
      
        // Build the leftOnes array
        // For each position, if it's a 1, extend the consecutive count from the left
        for (int i = 1; i <= arraySize; ++i) {
            if (nums[i - 1] == 1) {
                leftOnes[i] = leftOnes[i - 1] + 1;
            }
        }
      
        // Build the rightOnes array
        // For each position from right to left, if it's a 1, extend the consecutive count from the right
        for (int i = arraySize - 1; i >= 0; --i) {
            if (nums[i] == 1) {
                rightOnes[i] = rightOnes[i + 1] + 1;
            }
        }
      
        // Find the maximum length by trying to delete each element
        // When we delete element at position i, we can connect:
        // - consecutive 1s ending before position i (leftOnes[i])
        // - consecutive 1s starting after position i (rightOnes[i + 1])
        int maxLength = 0;
        for (int i = 0; i < arraySize; ++i) {
            int currentLength = leftOnes[i] + rightOnes[i + 1];
            maxLength = max(maxLength, currentLength);
        }
      
        return maxLength;
    }
};