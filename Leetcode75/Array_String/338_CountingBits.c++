class Solution {
public:
    vector<int> countBits(int n) {
        // Create a result vector of size n+1 to store bit counts for numbers 0 to n
        vector<int> result(n + 1);
      
        // Iterate through each number from 0 to n
        for (int i = 0; i <= n; ++i) {
            // Count the number of 1 bits in the binary representation of i
            // __builtin_popcount() is a GCC built-in function that counts set bits
            result[i] = __builtin_popcount(i);
        }
      
        // Return the result vector containing bit counts for all numbers
        return result;
    }
};