class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // Initialize two variables to track the smallest and middle values
        // in a potential increasing triplet subsequence
        int smallest = INT_MAX;  // Smallest value seen so far
        int middle = INT_MAX;    // Second smallest value that comes after 'smallest'
      
        // Iterate through each number in the array
        for (int current : nums) {
            // If current number is greater than middle, we found an increasing triplet
            // (smallest < middle < current)
            if (current > middle) {
                return true;
            }
          
            // If current number is less than or equal to smallest,
            // update smallest to potentially form a better triplet
            if (current <= smallest) {
                smallest = current;
            }
            // If current is between smallest and middle,
            // update middle (we have smallest < current)
            else {
                middle = current;
            }
        }
      
        // No increasing triplet found in the entire array
        return false;
    }
};