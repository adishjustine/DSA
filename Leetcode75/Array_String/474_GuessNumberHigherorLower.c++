/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    /**
     * Binary search to find the target number
     * @param n The upper bound of the search range [1, n]
     * @return The target number that was picked
     */
    int guessNumber(int n) {
        // Initialize binary search boundaries
        // Search range is [left, right] inclusive
        int left = 1;
        int right = n;
      
        // Continue searching while the range has more than one element
        while (left < right) {
            // Calculate middle point avoiding potential overflow
            // Using bit shift for division by 2
            int mid = left + ((right - left) >> 1);
          
            // Get feedback from guess API
            int result = guess(mid);
          
            // If mid is greater than or equal to target
            // Target must be in [left, mid]
            if (result <= 0) {
                right = mid;  // Include mid as it could be the answer
            } 
            // If mid is less than target
            // Target must be in [mid + 1, right]
            else {
                left = mid + 1;  // Exclude mid as it's definitely not the answer
            }
        }
      
        // When left == right, we've found the target
        return left;
    }
};
