/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * Finds the lowest common ancestor (LCA) of two nodes in a binary tree.
     * 
     * @param root The root of the binary tree
     * @param p First target node
     * @param q Second target node
     * @return The lowest common ancestor of nodes p and q
     */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: if root is null or root is one of the target nodes
        // Return root as it could be the LCA or indicate finding a target
        if (root == nullptr || root == p || root == q) {
            return root;
        }
      
        // Recursively search for p and q in the left subtree
        TreeNode* leftResult = lowestCommonAncestor(root->left, p, q);
      
        // Recursively search for p and q in the right subtree
        TreeNode* rightResult = lowestCommonAncestor(root->right, p, q);
      
        // If both left and right subtrees return non-null values,
        // it means p and q are found in different subtrees,
        // so current root is the LCA
        if (leftResult != nullptr && rightResult != nullptr) {
            return root;
        }
      
        // If only one subtree contains both nodes (or one node),
        // return the non-null result which represents the LCA
        return (leftResult != nullptr) ? leftResult : rightResult;
    }
};