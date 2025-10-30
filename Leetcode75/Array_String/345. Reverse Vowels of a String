class Solution {
public:
    string reverseVowels(string s) {
        // Create a lookup table for vowels (ASCII table size)
        // Using array for O(1) lookup time
        bool isVowel[128];
        memset(isVowel, false, sizeof(isVowel));
      
        // Mark all vowels (both lowercase and uppercase) in the lookup table
        for (char c : "aeiouAEIOU") {
            isVowel[c] = true;
        }
      
        // Initialize two pointers: left starting from beginning, right from end
        int left = 0;
        int right = s.size() - 1;
      
        // Use two-pointer technique to swap vowels
        while (left < right) {
            // Move left pointer forward until a vowel is found
            while (left < right && !isVowel[s[left]]) {
                ++left;
            }
          
            // Move right pointer backward until a vowel is found
            while (left < right && !isVowel[s[right]]) {
                --right;
            }
          
            // If both pointers point to vowels, swap them and move both pointers
            if (left < right) {
                swap(s[left], s[right]);
                ++left;
                --right;
            }
        }
      
        return s;
    }
};