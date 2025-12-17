class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
      
        // dp[i] represents the minimum cost to reach the top starting from step i
        // Initialize with -1 to indicate uncomputed state
        vector<int> dp(n, -1);
      
        // Recursive function with memoization to calculate minimum cost
        // Lambda function using explicit object parameter (C++23 feature)
        auto dfs = [&](this auto&& dfs, int currentStep) -> int {
            // Base case: if we've reached or passed the top, no cost needed
            if (currentStep >= n) {
                return 0;
            }
          
            // If already computed, return the memoized result
            if (dp[currentStep] != -1) {
                return dp[currentStep];
            }
          
            // Calculate minimum cost: current step cost + minimum of next two steps
            // We can either take 1 step or 2 steps from current position
            dp[currentStep] = cost[currentStep] + 
                              min(dfs(currentStep + 1), dfs(currentStep + 2));
          
            return dp[currentStep];
        };
      
        // We can start from either step 0 or step 1
        // Return the minimum cost between these two starting points
        return min(dfs(0), dfs(1));
    }
};