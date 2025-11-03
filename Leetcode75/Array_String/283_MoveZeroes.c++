class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // Position to place the next non-zero element
        int nonZeroPosition = 0;
        int arraySize = nums.size();
      
        // Iterate through the entire array
        for (int currentIndex = 0; currentIndex < arraySize; ++currentIndex) {
            // If current element is non-zero
            if (nums[currentIndex] != 0) {
                // Swap current non-zero element with the element at nonZeroPosition
                // This moves non-zero elements to the front while maintaining order
                swap(nums[currentIndex], nums[nonZeroPosition]);
                // Move the position for next non-zero element
                nonZeroPosition++;
            }
        }
        // After the loop, all non-zero elements are at the beginning in their original order,
        // and all zeros are automatically moved to the end
    }
};
