class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Initialize write pointer to track position for unique elements
        int writeIndex = 0;
      
        // Iterate through each element in the array
        for (int currentNum : nums) {
            // Add element if it's the first element OR different from the previous unique element
            if (writeIndex == 0 || currentNum != nums[writeIndex - 1]) {
                // Place the unique element at the write position and increment
                nums[writeIndex++] = currentNum;
            }
        }
      
        // Return the count of unique elements
        return writeIndex;
    }
};
