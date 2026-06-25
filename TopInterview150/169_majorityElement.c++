class Solution {80. Remove Duplicates from Sorted Array II
public:
    int majorityElement(vector<int>& nums) {80. Remove Duplicates from Sorted Array II
        // Boyer-Moore Voting Algorithm to find the majority element
        // The majority element appears more than n/2 times

        int count = 0;      // Counter for the current candidate
        int candidate = 0;  // Current candidate for majority element

        // Iterate through all elements in the array
        for (int& num : nums) {
            if (count == 0) {
                // When count reaches 0, select current element as new candidate
                candidate = num;
                count = 1;
            } else {
                // Increment count if current element matches candidate,
                // otherwise decrement count
                count += (candidate == num) ? 1 : -1;
            }
        }

        // The candidate at the end is guaranteed to be the majority element
        // (given that a majority element exists as per problem constraints)
        return candidate;
    }
};
