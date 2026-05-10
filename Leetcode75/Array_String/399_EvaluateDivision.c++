class Solution {
public:
    // Parent mapping for union-find structure
    unordered_map<string, string> parent;
    // Weight/ratio from current node to its parent
    unordered_map<string, double> weight;

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int numEquations = equations.size();
      
        // Initialize union-find structure
        // Each variable is initially its own parent with weight 1.0
        for (const auto& equation : equations) {
            parent[equation[0]] = equation[0];
            parent[equation[1]] = equation[1];
            weight[equation[0]] = 1.0;
            weight[equation[1]] = 1.0;
        }
      
        // Build union-find structure with weighted edges
        for (int i = 0; i < numEquations; ++i) {
            vector<string> equation = equations[i];
            string numerator = equation[0];
            string denominator = equation[1];
          
            // Find root parents of both variables
            string parentNumerator = find(numerator);
            string parentDenominator = find(denominator);
          
            // Skip if already in the same group
            if (parentNumerator == parentDenominator) {
                continue;
            }
          
            // Union: make parentNumerator point to parentDenominator
            parent[parentNumerator] = parentDenominator;
            // Update weight to maintain the ratio relationship
            // values[i] = numerator / denominator
            // weight[parentNumerator] = (denominator's path product) * values[i] / (numerator's path product)
            weight[parentNumerator] = weight[denominator] * values[i] / weight[numerator];
        }
      
        // Process queries
        int numQueries = queries.size();
        vector<double> results(numQueries);
      
        for (int i = 0; i < numQueries; ++i) {
            string dividend = queries[i][0];
            string divisor = queries[i][1];
          
            // Check if both variables exist and belong to the same connected component
            if (parent.find(dividend) == parent.end() || 
                parent.find(divisor) == parent.end() || 
                find(dividend) != find(divisor)) {
                results[i] = -1.0;
            } else {
                // Calculate the ratio: dividend / divisor
                results[i] = weight[dividend] / weight[divisor];
            }
        }
      
        return results;
    }

    // Find root parent with path compression and weight update
    string find(string variable) {
        if (parent[variable] != variable) {
            string originalParent = parent[variable];
            // Recursively find root and compress path
            parent[variable] = find(parent[variable]);
            // Update weight: multiply weights along the path
            weight[variable] *= weight[originalParent];
        }
        return parent[variable];
    }
};
