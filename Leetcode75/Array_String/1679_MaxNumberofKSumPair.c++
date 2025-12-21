class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        // Sort the array to enable two-pointer approach
        sort(nums.begin(), nums.end());
      
        // Initialize operation counter
        int operationCount = 0;
      
        // Set up two pointers: left starting from beginning, right from end
        int left = 0;
        int right = nums.size() - 1;
      
        // Use two-pointer technique to find pairs that sum to k
        while (left < right) {
            int currentSum = nums[left] + nums[right];
          
            if (currentSum == k) {
                // Found a valid pair, move both pointers inward
                left++;
                right--;
                operationCount++;
            } 
            else if (currentSum > k) {
                // Sum is too large, decrease it by moving right pointer left
                right--;
            } 
            else {
                // Sum is too small, increase it by moving left pointer right
                left++;
            }
        }
      
        return operationCount;
    }
};
