class Solution {
public:
    /**
     * Count the number of good nodes in a binary tree.
     * A node is considered "good" if the path from root to that node
     * doesn't contain any node with a value greater than the node's value.
     * 
     * @param root The root of the binary tree
     * @return The count of good nodes in the tree
     */
    int goodNodes(TreeNode* root) {
        int goodNodeCount = 0;
      
        // Define a lambda function for depth-first search traversal
        // Captures goodNodeCount by reference to update the count
        function<void(TreeNode*, int)> dfs = [&](TreeNode* node, int maxSoFar) {
            // Base case: if node is null, return
            if (!node) {
                return;
            }
          
            // Check if current node is a good node
            // A node is good if its value is >= all values on the path from root
            if (maxSoFar <= node->val) {
                ++goodNodeCount;
                // Update the maximum value seen so far on this path
                maxSoFar = node->val;
            }
          
            // Recursively traverse left subtree with updated maximum
            dfs(node->left, maxSoFar);
          
            // Recursively traverse right subtree with updated maximum
            dfs(node->right, maxSoFar);
        };
      
        // Start DFS from root with initial maximum as negative infinity
        // Using -1e6 as a sufficiently small value (constraint: node values are in range [-10^4, 10^4])
        dfs(root, -1000000);
      
        return goodNodeCount;
    }
};