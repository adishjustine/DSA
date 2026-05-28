class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flipsCount = 0;
      
        // Check each bit position (0 to 31 for 32-bit integers)
        for (int bitPosition = 0; bitPosition < 32; ++bitPosition) {
            // Extract the i-th bit from each number
            int bitA = (a >> bitPosition) & 1;
            int bitB = (b >> bitPosition) & 1;
            int bitC = (c >> bitPosition) & 1;
          
            // Calculate flips needed for current bit position
            if (bitC == 0) {
                // If target bit is 0, both a and b bits must be 0
                // Need to flip all 1s to 0s
                flipsCount += bitA + bitB;
            } else {
                // If target bit is 1, at least one of a or b bits must be 1
                // Only need to flip if both are 0
                if (bitA == 0 && bitB == 0) {
                    flipsCount += 1;
                }
            }
        }
      
        return flipsCount;
    }
};
