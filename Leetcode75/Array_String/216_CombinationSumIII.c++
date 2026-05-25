class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;           // Store all valid combinations
        vector<int> currentCombination;       // Current combination being built
      
        // Define recursive DFS function using lambda
        function<void(int, int)> backtrack = [&](int startNum, int remainingSum) {
            // Base case: found a valid combination
            if (remainingSum == 0) {
                if (currentCombination.size() == k) {
                    result.emplace_back(currentCombination);
                }
                return;
            }
          
            // Pruning conditions:
            // 1. startNum > 9: exceeded valid digit range (1-9)
            // 2. startNum > remainingSum: current number is too large
            // 3. currentCombination.size() >= k: already have k numbers
            if (startNum > 9 || startNum > remainingSum || currentCombination.size() >= k) {
                return;
            }
          
            // Choice 1: Include current number in the combination
            currentCombination.emplace_back(startNum);
            backtrack(startNum + 1, remainingSum - startNum);
            currentCombination.pop_back();  // Backtrack
          
            // Choice 2: Skip current number and try next
            backtrack(startNum + 1, remainingSum);
        };
      
        // Start DFS from digit 1 with target sum n
        backtrack(1, n);
      
        return result;
    }
};
