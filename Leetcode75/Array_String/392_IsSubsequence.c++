class Solution {
public:
    bool isSubsequence(string s, string t) {
        // Get the lengths of both strings
        int sLength = s.size();
        int tLength = t.size();
      
        // Initialize two pointers:
        // sIndex: tracks current position in string s (subsequence)
        // tIndex: tracks current position in string t (main string)
        int sIndex = 0;
        int tIndex = 0;
      
        // Iterate through string t while both pointers are within bounds
        for (; sIndex < sLength && tIndex < tLength; ++tIndex) {
            // If characters match, move pointer in string s forward
            if (s[sIndex] == t[tIndex]) {
                ++sIndex;
            }
            // Otherwise, continue to next character in t (tIndex increments in loop)
        }
      
        // If we've matched all characters in s, then s is a subsequence of t
        return sIndex == sLength;
    }
};