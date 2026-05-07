class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        // Base case: empty tree
        if (!root) {
            return root;
        }
      
        // Search for the node to delete in the left subtree
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
            return root;
        }
      
        // Search for the node to delete in the right subtree
        if (root->val < key) {
            root->right = deleteNode(root->right, key);
            return root;
        }
      
        // Found the node to delete (root->val == key)
      
        // Case 1: Node has no left child - return right child
        if (!root->left) {
            return root->right;
        }
      
        // Case 2: Node has no right child - return left child
        if (!root->right) {
            return root->left;
        }
      
        // Case 3: Node has both children
        // Find the leftmost node in the right subtree (inorder successor)
        TreeNode* minNodeInRightSubtree = root->right;
        while (minNodeInRightSubtree->left) {
            minNodeInRightSubtree = minNodeInRightSubtree->left;
        }
      
        // Attach the left subtree to the leftmost node of right subtree
        minNodeInRightSubtree->left = root->left;
      
        // Replace the node to be deleted with its right subtree
        root = root->right;
      
        return root;
    }
};