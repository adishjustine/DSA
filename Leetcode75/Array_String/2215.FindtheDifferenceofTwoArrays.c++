class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        // Convert both arrays to sets to remove duplicates and enable O(1) lookup
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
      
        // Initialize result vector with 2 empty vectors
        vector<vector<int>> result(2);
      
        // Find elements in set1 that are not in set2
        for (int value : set1) {
            if (!set2.count(value)) {  // Using count() for C++ compatibility
                result[0].push_back(value);
            }
        }
      
        // Find elements in set2 that are not in set1
        for (int value : set2) {
            if (!set1.count(value)) {  // Using count() for C++ compatibility
                result[1].push_back(value);
            }
        }
      
        return result;
    }
};