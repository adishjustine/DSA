class Solution {
public:
    int pairSum(ListNode* head) {
        // Store all node values in a vector for easy access
        vector<int> values;
      
        // Traverse the linked list and collect all values
        ListNode* current = head;
        while (current != nullptr) {
            values.push_back(current->val);
            current = current->next;
        }
      
        // Initialize the maximum twin sum
        int maxTwinSum = 0;
        int n = values.size();
      
        // Calculate twin sums for each pair (i-th and (n-1-i)-th nodes)
        // Only need to check the first half of nodes
        for (int i = 0; i < n / 2; ++i) {
            int twinSum = values[i] + values[n - 1 - i];
            maxTwinSum = max(maxTwinSum, twinSum);
        }
      
        return maxTwinSum;
    }
};