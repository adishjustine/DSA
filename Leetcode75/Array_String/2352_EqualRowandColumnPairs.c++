class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int count = 0;  // Total count of equal row-column pairs
      
        // Iterate through each row index
        for (int row = 0; row < n; ++row) {
            // Iterate through each column index
            for (int col = 0; col < n; ++col) {
                bool isEqual = true;  // Flag to check if row[row] equals column[col]
              
                // Compare each element of row[row] with corresponding element of column[col]
                for (int k = 0; k < n; ++k) {
                    // Check if element at position k in row doesn't match element at position k in column
                    if (grid[row][k] != grid[k][col]) {
                        isEqual = false;
                        break;  // Early exit if mismatch found
                    }
                }
              
                // Increment count if the row and column are equal
                if (isEqual) {
                    count++;
                }
            }
        }
      
        return count;
    }
};