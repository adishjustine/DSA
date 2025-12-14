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
     * Determines if two binary trees have the same leaf value sequence
     * @param root1 - Root of the first binary tree
     * @param root2 - Root of the second binary tree
     * @return true if both trees have identical leaf sequences, false otherwise
     */
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        // Collect leaf values from both trees
        vector<int> leafSequence1, leafSequence2;
      
        // Perform depth-first search to collect leaves
        collectLeaves(root1, leafSequence1);
        collectLeaves(root2, leafSequence2);
      
        // Compare the two leaf sequences
        return leafSequence1 == leafSequence2;
    }

private:
    /**
     * Helper function to collect all leaf node values using DFS
     * @param node - Current node being processed
     * @param leafValues - Vector to store leaf values in left-to-right order
     */
    void collectLeaves(TreeNode* node, vector<int>& leafValues) {
        // Base case: null node
        if (!node) {
            return;
        }
      
        // Check if current node is a leaf (no left and right children)
        if (!node->left && !node->right) {
            leafValues.push_back(node->val);
            return;
        }
      
        // Recursively traverse left subtree
        if (node->left) {
            collectLeaves(node->left, leafValues);
        }
      
        // Recursively traverse right subtree
        if (node->right) {
            collectLeaves(node->right, leafValues);
        }
    }
};