class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
      
        // Create pairs of (nums2[i], nums1[i]) and store negative of nums2[i] for sorting
        // We negate nums2[i] to sort in descending order of nums2 values
        vector<pair<int, int>> pairs(n);
        for (int i = 0; i < n; ++i) {
            pairs[i] = {-nums2[i], nums1[i]};
        }
      
        // Sort pairs by nums2 values in descending order (due to negation)
        sort(pairs.begin(), pairs.end());
      
        // Min heap to maintain k largest elements from nums1
        priority_queue<int, vector<int>, greater<int>> minHeap;
      
        long long maxResult = 0;
        long long currentSum = 0;
      
        // Iterate through pairs in descending order of nums2 values
        for (auto& [negatedNum2Value, num1Value] : pairs) {
            // Add current nums1 value to sum and heap
            currentSum += num1Value;
            minHeap.push(num1Value);
          
            // When we have exactly k elements, calculate score
            if (minHeap.size() == k) {
                // Score = sum of k nums1 values * minimum nums2 value among selected
                // negatedNum2Value is negative, so we negate it back
                maxResult = max(maxResult, currentSum * (-negatedNum2Value));
              
                // Remove smallest nums1 value to make room for next iteration
                currentSum -= minHeap.top();
                minHeap.pop();
            }
        }
      
        return maxResult;
    }
};
