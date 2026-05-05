class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
      
        // Handle empty tree case
        if (!root) {
            return result;
        }
      
        // Initialize queue for BFS traversal
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
      
        // Process tree level by level
        while (!nodeQueue.empty()) {
            int levelSize = nodeQueue.size();
          
            // Process all nodes at current level
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* currentNode = nodeQueue.front();
                nodeQueue.pop();
              
                // Add the rightmost node of current level to result
                // (last node when i == levelSize - 1)
                if (i == levelSize - 1) {
                    result.push_back(currentNode->val);
                }
              
                // Add children to queue for next level processing
                // Add left child first, then right child
                if (currentNode->left) {
                    nodeQueue.push(currentNode->left);
                }
                if (currentNode->right) {
                    nodeQueue.push(currentNode->right);
                }
            }
        }
      
        return result;
    }
};