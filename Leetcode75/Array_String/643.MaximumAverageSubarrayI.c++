class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // Calculate the sum of the first k elements (initial window)
        int windowSum = accumulate(nums.begin(), nums.begin() + k, 0);
      
        // Initialize the maximum sum with the first window's sum
        int maxSum = windowSum;
      
        // Slide the window through the rest of the array
        for (int i = k; i < nums.size(); ++i) {
            // Update window sum by adding new element and removing the leftmost element
            windowSum += nums[i] - nums[i - k];
          
            // Update maximum sum if current window sum is greater
            maxSum = max(maxSum, windowSum);
        }
      
        // Return the maximum average by dividing max sum by k
        return static_cast<double>(maxSum) / k;
    }
};