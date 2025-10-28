class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        // Find the maximum number of candies any kid currently has
        int maxCandies = *max_element(candies.begin(), candies.end());
      
        // Initialize result vector to store whether each kid can have the most candies
        vector<bool> result;
      
        // Check each kid: if their candies plus extra candies >= max, they can have the most
        for (int currentCandies : candies) {
            result.push_back(currentCandies + extraCandies >= maxCandies);
        }
      
        return result;
    }
};
