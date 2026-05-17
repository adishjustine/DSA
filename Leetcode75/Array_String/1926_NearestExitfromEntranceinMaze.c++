class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int rows = maze.size();
        int cols = maze[0].size();
      
        // Direction vectors for moving up, right, down, left
        // Using the pattern: dirs[i] and dirs[i+1] form (dx, dy) pairs
        int directions[5] = {-1, 0, 1, 0, -1};
      
        // BFS queue to store positions to explore
        queue<pair<int, int>> bfsQueue;
      
        // Start BFS from entrance position
        bfsQueue.emplace(entrance[0], entrance[1]);
      
        // Mark entrance as visited by changing it to wall
        maze[entrance[0]][entrance[1]] = '+';
      
        // BFS level by level, tracking distance (number of steps)
        for (int distance = 1; !bfsQueue.empty(); ++distance) {
            // Process all cells at current distance level
            int currentLevelSize = bfsQueue.size();
          
            for (int i = 0; i < currentLevelSize; ++i) {
                // Get current position from queue
                auto [currentRow, currentCol] = bfsQueue.front();
                bfsQueue.pop();
              
                // Explore all 4 adjacent directions
                for (int dir = 0; dir < 4; ++dir) {
                    int nextRow = currentRow + directions[dir];
                    int nextCol = currentCol + directions[dir + 1];
                  
                    // Check if next position is valid and is an empty cell
                    if (nextRow >= 0 && nextRow < rows && 
                        nextCol >= 0 && nextCol < cols && 
                        maze[nextRow][nextCol] == '.') {
                      
                        // Check if this position is an exit (on the border)
                        if (nextRow == 0 || nextRow == rows - 1 || 
                            nextCol == 0 || nextCol == cols - 1) {
                            return distance;
                        }
                      
                        // Mark as visited and add to queue for further exploration
                        maze[nextRow][nextCol] = '+';
                        bfsQueue.emplace(nextRow, nextCol);
                    }
                }
            }
        }
      
        // No exit found
        return -1;
    }
};
