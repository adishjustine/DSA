class Solution {
public:
    string removeStars(string s) {
        // Initialize result string to store characters after star removal
        string result;
      
        // Iterate through each character in the input string
        for (char current_char : s) {
            if (current_char == '*') {
                // If current character is a star, remove the last character from result
                result.pop_back();
            } else {
                // If current character is not a star, append it to result
                result.push_back(current_char);
            }
        }
      
        // Return the final string after all star operations
        return result;
    }
};