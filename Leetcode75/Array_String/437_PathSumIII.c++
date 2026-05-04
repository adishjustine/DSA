class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        // Map to store prefix sum frequencies
        // Key: prefix sum value, Value: count of occurrences
        unordered_map<long long, int> prefixSumCount;
      
        // Initialize with 0 sum having count 1 (empty path)
        // This handles cases where a path from root equals targetSum
        prefixSumCount[0] = 1;
      
        // Define recursive DFS function using lambda with explicit this capture
        auto depthFirstSearch = [&](this auto&& depthFirstSearch, 
                                   TreeNode* currentNode, 
                                   long long currentPrefixSum) -> int {
            // Base case: if node is null, no paths found
            if (!currentNode) {
                return 0;
            }
          
            // Update current prefix sum by adding current node's value
            currentPrefixSum += currentNode->val;
          
            // Check if there exists a previous prefix sum such that
            // currentPrefixSum - previousPrefixSum = targetSum
            // This means: previousPrefixSum = currentPrefixSum - targetSum
            int pathCount = prefixSumCount[currentPrefixSum - targetSum];
          
            // Add current prefix sum to the map for use by descendant nodes
            ++prefixSumCount[currentPrefixSum];
          
            // Recursively search left and right subtrees
            pathCount += depthFirstSearch(currentNode->left, currentPrefixSum);
            pathCount += depthFirstSearch(currentNode->right, currentPrefixSum);
          
            // Backtrack: remove current prefix sum from map
            // This ensures it's not available to nodes in other branches
            --prefixSumCount[currentPrefixSum];
          
            return pathCount;
        };
      
        // Start DFS from root with initial prefix sum of 0
        return depthFirstSearch(root, 0);
    }
};