class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // writeIndex keeps track of where to write the next valid element
        int writeIndex = 0;
      
        // Iterate through each element in the array
        for (int currentNum : nums) {
            // Allow element if:
            // 1. We have less than 2 elements written (writeIndex < 2), OR
            // 2. Current element is different from the element 2 positions back
            //    (this ensures at most 2 duplicates)
            if (writeIndex < 2 || currentNum != nums[writeIndex - 2]) {
                // Write the current element at writeIndex position and increment
                nums[writeIndex++] = currentNum;
            }
        }
      
        // Return the length of the modified array
        return writeIndex;
    }
};
