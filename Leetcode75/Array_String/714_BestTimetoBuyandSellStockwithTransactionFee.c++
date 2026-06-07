class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
      
        // dp[i][state]: maximum profit starting from day i
        // state = 0: currently not holding stock
        // state = 1: currently holding stock
        vector<vector<int>> dp(n, vector<int>(2, -1));
      
        // Recursive function with memoization
        function<int(int, int)> calculateMaxProfit = [&](int day, int holdingStock) -> int {
            // Base case: no more days to trade
            if (day >= n) {
                return 0;
            }
          
            // Return memoized result if already calculated
            if (dp[day][holdingStock] != -1) {
                return dp[day][holdingStock];
            }
          
            int maxProfitFromDay;
          
            if (holdingStock) {
                // Currently holding stock: can either sell or hold
                int profitIfSell = prices[day] - fee + calculateMaxProfit(day + 1, 0);
                int profitIfHold = calculateMaxProfit(day + 1, 1);
                maxProfitFromDay = max(profitIfSell, profitIfHold);
            } else {
                // Currently not holding stock: can either buy or skip
                int profitIfBuy = -prices[day] + calculateMaxProfit(day + 1, 1);
                int profitIfSkip = calculateMaxProfit(day + 1, 0);
                maxProfitFromDay = max(profitIfBuy, profitIfSkip);
            }
          
            // Memoize and return the result
            dp[day][holdingStock] = maxProfitFromDay;
            return maxProfitFromDay;
        };
      
        // Start from day 0 without holding any stock
        return calculateMaxProfit(0, 0);
    }
};
