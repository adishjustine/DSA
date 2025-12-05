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
     * Searches for a node with the given value in a Binary Search Tree (BST)
     * @param root - The root node of the BST
     * @param val - The target value to search for
     * @return The node containing the target value, or nullptr if not found
     */
    TreeNode* searchBST(TreeNode* root, int val) {
        // Base case: if root is null or we found the target value
        if (root == nullptr || root->val == val) {
            return root;
        }
      
        // BST property: if target is less than current node, search left subtree
        // Otherwise, search right subtree
        if (root->val > val) {
            return searchBST(root->left, val);
        } else {
            return searchBST(root->right, val);
        }
    }
};