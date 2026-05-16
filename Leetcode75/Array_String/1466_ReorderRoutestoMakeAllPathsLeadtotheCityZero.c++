class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        // Build adjacency list with bidirectional edges
        // Each edge stores: (neighbor_node, needs_reversal_flag)
        // needs_reversal_flag = 1 if edge points away from node 0, 0 otherwise
        vector<vector<pair<int, int>>> adjacencyList(n);
      
        for (const auto& connection : connections) {
            int fromNode = connection[0];
            int toNode = connection[1];
          
            // Original edge: fromNode -> toNode (needs reversal if used)
            adjacencyList[fromNode].emplace_back(toNode, 1);
          
            // Reverse edge: toNode -> fromNode (doesn't need reversal)
            adjacencyList[toNode].emplace_back(fromNode, 0);
        }
      
        // DFS to count edges that need to be reversed
        // currentNode: current node being visited
        // parentNode: parent node to avoid revisiting
        function<int(int, int)> countReversals = [&](int currentNode, int parentNode) -> int {
            int reversalCount = 0;
          
            // Explore all neighbors of current node
            for (const auto& [neighborNode, needsReversal] : adjacencyList[currentNode]) {
                // Skip parent node to avoid going back
                if (neighborNode != parentNode) {
                    // Add reversal cost if edge needs to be reversed
                    // Recursively count reversals in subtree
                    reversalCount += needsReversal + countReversals(neighborNode, currentNode);
                }
            }
          
            return reversalCount;
        };
      
        // Start DFS from node 0 with no parent (-1)
        return countReversals(0, -1);
    }
};
