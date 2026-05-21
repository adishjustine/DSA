class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int totalWorkers = costs.size();
      
        // Special case: if the candidate pools from both ends overlap or cover all workers
        // Simply sort and pick the k cheapest workers
        if (candidates * 2 >= totalWorkers) {
            sort(costs.begin(), costs.end());
            return accumulate(costs.begin(), costs.begin() + k, 0LL);
        }
      
        // Min heap to store (cost, index) pairs, automatically sorted by cost
        using CostIndexPair = pair<int, int>;
        priority_queue<CostIndexPair, vector<CostIndexPair>, greater<CostIndexPair>> minHeap;
      
        // Initialize heap with candidates from both ends
        for (int i = 0; i < candidates; ++i) {
            minHeap.emplace(costs[i], i);                    // Add from left side
            minHeap.emplace(costs[totalWorkers - i - 1], totalWorkers - i - 1);  // Add from right side
        }
      
        long long totalCostSum = 0;
        int leftBoundary = candidates;              // Next available index from left
        int rightBoundary = totalWorkers - candidates - 1;  // Next available index from right
      
        // Hire k workers
        while (k--) {
            // Get the worker with minimum cost
            auto [workerCost, workerIndex] = minHeap.top();
            minHeap.pop();
            totalCostSum += workerCost;
          
            // If all remaining workers are already in the heap, continue
            if (leftBoundary > rightBoundary) {
                continue;
            }
          
            // Refill the heap based on which side the hired worker came from
            if (workerIndex < leftBoundary) {
                // Worker was from left pool, add next worker from left
                minHeap.emplace(costs[leftBoundary], leftBoundary);
                leftBoundary++;
            } else {
                // Worker was from right pool, add next worker from right
                minHeap.emplace(costs[rightBoundary], rightBoundary);
                rightBoundary--;
            }
        }
      
        return totalCostSum;
    }
};
