class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
      
        // Queue to store positions of rotten oranges for BFS
        queue<pair<int, int>> rottenQueue;
      
        // Count of fresh oranges
        int freshCount = 0;
      
        // Initial scan: count fresh oranges and enqueue all rotten oranges
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == 1) {
                    // Fresh orange found
                    ++freshCount;
                } else if (grid[row][col] == 2) {
                    // Rotten orange found, add to queue
                    rottenQueue.emplace(row, col);
                }
            }
        }
      
        // Direction vectors for 4-directional movement (up, right, down, left)
        const int directions[5] = {-1, 0, 1, 0, -1};
      
        // BFS to rot adjacent fresh oranges level by level
        // Start from minute 1 since we're counting elapsed time
        for (int minute = 1; !rottenQueue.empty() && freshCount > 0; ++minute) {
            // Process all oranges that rot in the current minute
            int currentLevelSize = rottenQueue.size();
          
            for (int i = 0; i < currentLevelSize; ++i) {
                // Get current rotten orange position
                auto [currentRow, currentCol] = rottenQueue.front();
                rottenQueue.pop();
              
                // Check all 4 adjacent cells
                for (int dir = 0; dir < 4; ++dir) {
                    int nextRow = currentRow + directions[dir];
                    int nextCol = currentCol + directions[dir + 1];
                  
                    // Check if adjacent cell is valid and contains a fresh orange
                    if (nextRow >= 0 && nextRow < rows && 
                        nextCol >= 0 && nextCol < cols && 
                        grid[nextRow][nextCol] == 1) {
                      
                        // Rot the fresh orange
                        grid[nextRow][nextCol] = 2;
                        rottenQueue.emplace(nextRow, nextCol);
                      
                        // Decrease fresh orange count and check if all are rotten
                        if (--freshCount == 0) {
                            return minute;
                        }
                    }
                }
            }
        }
      
        // If there are still fresh oranges, return -1; otherwise return 0
        return freshCount > 0 ? -1 : 0;
    }
};