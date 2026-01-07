class Solution {
public:
    bool closeStrings(string word1, string word2) {
        // Initialize frequency arrays for both strings (26 letters in alphabet)
        int frequency1[26]{};
        int frequency2[26]{};
      
        // Count character frequencies in word1
        for (char& c : word1) {
            ++frequency1[c - 'a'];
        }
      
        // Count character frequencies in word2
        for (char& c : word2) {
            ++frequency2[c - 'a'];
        }
      
        // Check if both strings have the same set of characters
        // If one string has a character that the other doesn't, they can't be close
        for (int i = 0; i < 26; ++i) {
            if ((frequency1[i] == 0) != (frequency2[i] == 0)) {
                return false;
            }
        }
      
        // Sort frequency arrays to check if they have the same frequency distribution
        sort(frequency1, frequency1 + 26);
        sort(frequency2, frequency2 + 26);
      
        // Check if sorted frequency arrays are equal
        // This ensures both strings have the same frequency values (just possibly for different characters)
        return equal(frequency1, frequency1 + 26, frequency2);
    }
};
