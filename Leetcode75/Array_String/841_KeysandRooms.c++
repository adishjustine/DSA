class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int totalRooms = rooms.size();
        int visitedCount = 0;
      
        // Track which rooms have been visited
        vector<bool> visited(totalRooms, false);
      
        // Depth-first search to explore all reachable rooms
        function<void(int)> dfs = [&](int currentRoom) {
            // Skip if already visited
            if (visited[currentRoom]) {
                return;
            }
          
            // Mark current room as visited
            visited[currentRoom] = true;
            visitedCount++;
          
            // Visit all rooms accessible from current room's keys
            for (int nextRoom : rooms[currentRoom]) {
                dfs(nextRoom);
            }
        };
      
        // Start exploring from room 0 (which is initially unlocked)
        dfs(0);
      
        // Check if all rooms were visited
        return visitedCount == totalRooms;
    }
};