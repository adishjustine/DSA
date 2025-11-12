class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // Initialize left sum as 0 and right sum as total sum of all elements
        int leftSum = 0;
        int rightSum = accumulate(nums.begin(), nums.end(), 0);
      
        // Iterate through each index to find the pivot
        for (int i = 0; i < nums.size(); ++i) {
            // Subtract current element from right sum (excluding current element)
            rightSum -= nums[i];
          
            // Check if left sum equals right sum (pivot found)
            if (leftSum == rightSum) {
                return i;  // Return the pivot index
            }
          
            // Add current element to left sum for next iteration
            leftSum += nums[i];
        }
        return -1;
    }
};