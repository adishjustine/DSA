class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
      
        // Iterate through each position in the flowerbed
        for (int i = 0; i < size; ++i) {
            // Check the left neighbor (0 if at the beginning)
            int leftNeighbor = (i == 0) ? 0 : flowerbed[i - 1];
          
            // Check the right neighbor (0 if at the end)
            int rightNeighbor = (i == size - 1) ? 0 : flowerbed[i + 1];
          
            // If current position and both neighbors are empty (sum equals 0)
            // then we can plant a flower here
            if (leftNeighbor + flowerbed[i] + rightNeighbor == 0) {
                // Plant a flower at current position
                flowerbed[i] = 1;
              
                // Decrease the number of flowers needed
                --n;
            }
        }
      
        // Return true if we've planted all required flowers (n <= 0)
        return n <= 0;
    }
};
