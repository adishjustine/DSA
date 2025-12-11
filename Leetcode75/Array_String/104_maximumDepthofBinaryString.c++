/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    /**
     * Calculate the maximum depth of a binary tree.
     * The maximum depth is the number of nodes along the longest path 
     * from the root node down to the farthest leaf node.
     * 
     * @param root - The root node of the binary tree
     * @return The maximum depth of the tree
     */
    int maxDepth(TreeNode* root) {
        // Base case: if the current node is null, depth is 0
        if (!root) {
            return 0;
        }
      
        // Recursively calculate the depth of left subtree
        int leftDepth = maxDepth(root->left);
      
        // Recursively calculate the depth of right subtree
        int rightDepth = maxDepth(root->right);
      
        // The depth of current node is 1 plus the maximum depth of its subtrees
        return 1 + std::max(leftDepth, rightDepth);
    }
};