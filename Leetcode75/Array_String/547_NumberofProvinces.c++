class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int provinceCount = 0;
        vector<bool> visited(n, false);  // Track visited cities
      
        // Define DFS function to explore all cities in a province
        function<void(int)> dfs = [&](int city) -> void {
            visited[city] = true;
          
            // Visit all directly connected cities
            for (int neighbor = 0; neighbor < n; ++neighbor) {
                if (!visited[neighbor] && isConnected[city][neighbor] == 1) {
                    dfs(neighbor);
                }
            }
        };
      
        // Count the number of provinces (connected components)
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                // Found a new province, explore all cities in it
                dfs(i);
                provinceCount++;
            }
        }
      
        return provinceCount;
    }
};
