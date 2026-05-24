class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        int firstTrueIndex = -1;

        // Binary search using the template: find first index where nums[mid] > nums[mid + 1]
        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Feasible condition: nums[mid] > nums[mid + 1]
            // For last element, treat as feasible (nums[n] = -infinity)
            if (mid == n - 1 || nums[mid] > nums[mid + 1]) {
                firstTrueIndex = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        // firstTrueIndex points to a peak element
        return firstTrueIndex;
    }
};
