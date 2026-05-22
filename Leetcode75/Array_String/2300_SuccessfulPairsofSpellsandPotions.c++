class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        // Sort potions array in ascending order for binary search
        sort(potions.begin(), potions.end());

        // Result vector to store count of successful pairs for each spell
        vector<int> result;

        // Get the total number of potions
        int potionCount = potions.size();

        // Iterate through each spell
        for (int& spellStrength : spells) {
            // Binary search using first_true_index template
            // Find first potion where spell * potion >= success
            int left = 0;
            int right = potionCount - 1;
            int firstTrueIndex = potionCount;  // Default: no valid potion found

            while (left <= right) {
                int mid = left + (right - left) / 2;

                // Check if current spell * potion meets success threshold
                if ((long long) spellStrength * potions[mid] >= success) {
                    // Found a valid potion, record and search for earlier one
                    firstTrueIndex = mid;
                    right = mid - 1;
                } else {
                    // Not successful, search in right half
                    left = mid + 1;
                }
            }

            // Calculate number of successful pairs
            // All potions from firstTrueIndex to end form successful pairs
            result.push_back(potionCount - firstTrueIndex);
        }

        return result;
    }
};
