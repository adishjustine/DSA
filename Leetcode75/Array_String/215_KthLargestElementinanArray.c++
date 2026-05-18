class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        // Convert k-th largest to (n-k)-th smallest for easier processing
        k = n - k;
      
        // Lambda function for QuickSelect algorithm
        auto quickSelect = [&](auto&& quickSelect, int left, int right) -> int {
            // Base case: single element
            if (left == right) {
                return nums[left];
            }
          
            // Initialize two pointers for partitioning
            int i = left - 1;
            int j = right + 1;
          
            // Choose middle element as pivot
            int pivot = nums[(left + right) >> 1];
          
            // Partition the array around the pivot
            while (i < j) {
                // Move i pointer to the right until finding element >= pivot
                while (nums[++i] < pivot) {
                    // Empty body - increment happens in condition
                }
              
                // Move j pointer to the left until finding element <= pivot
                while (nums[--j] > pivot) {
                    // Empty body - decrement happens in condition
                }
              
                // Swap elements if pointers haven't crossed
                if (i < j) {
                    swap(nums[i], nums[j]);
                }
            }
          
            // After partition, elements at indices <= j are <= pivot
            // Elements at indices > j are > pivot
          
            // If k is in the right partition, search right side
            if (j < k) {
                return quickSelect(quickSelect, j + 1, right);
            }
            // Otherwise, search left side (including j)
            return quickSelect(quickSelect, left, j);
        };
      
        // Start QuickSelect on the entire array
        return quickSelect(quickSelect, 0, n - 1);
    }
};
