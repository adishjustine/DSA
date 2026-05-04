class Solution {
public:
    int longestZigZag(TreeNode* root) {
        maxZigZagLength = 0;
        dfs(root, 0, 0);
        return maxZigZagLength;
    }

private:
    int maxZigZagLength;  // Stores the maximum zigzag path length found
  
    /**
     * Performs depth-first search to find the longest zigzag path
     * @param node: Current node being processed
     * @param leftLength: Length of zigzag path if we came from right (next move should be left)
     * @param rightLength: Length of zigzag path if we came from left (next move should be right)
     */
    void dfs(TreeNode* node, int leftLength, int rightLength) {
        // Base case: if node is null, return
        if (node == nullptr) {
            return;
        }
      
        // Update the maximum zigzag length with current path lengths
        maxZigZagLength = std::max(maxZigZagLength, std::max(leftLength, rightLength));
      
        // Move to left child: 
        // - If we go left, the previous right length + 1 becomes the new left length
        // - Reset right length to 0 since we're starting a new potential zigzag
        dfs(node->left, rightLength + 1, 0);
      
        // Move to right child:
        // - If we go right, the previous left length + 1 becomes the new right length  
        // - Reset left length to 0 since we're starting a new potential zigzag
        dfs(node->right, 0, leftLength + 1);
    }
};
   