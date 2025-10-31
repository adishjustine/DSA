class Solution {
public:
    string reverseWords(string s) {
        int readIndex = 0;      // Index for reading characters from original string
        int writeIndex = 0;     // Index for writing characters to compressed string
        int stringLength = s.size();
      
        // Process the entire string
        while (readIndex < stringLength) {
            // Skip leading spaces for current word
            while (readIndex < stringLength && s[readIndex] == ' ') {
                ++readIndex;
            }
          
            // Process a word if we haven't reached the end
            if (readIndex < stringLength) {
                // Add a space separator between words (except before the first word)
                if (writeIndex != 0) {
                    s[writeIndex++] = ' ';
                }
              
                // Mark the start position of current word
                int wordStartIndex = readIndex;
              
                // Copy the current word to the write position
                while (wordStartIndex < stringLength && s[wordStartIndex] != ' ') {
                    s[writeIndex++] = s[wordStartIndex++];
                }
              
                // Reverse the current word in-place
                // Calculate word boundaries: start = writeIndex - wordLength, end = writeIndex
                int wordLength = wordStartIndex - readIndex;
                reverse(s.begin() + writeIndex - wordLength, s.begin() + writeIndex);
              
                // Move read pointer to the next position after current word
                readIndex = wordStartIndex;
            }
        }
      
        // Remove extra characters after compression
        s.erase(s.begin() + writeIndex, s.end());
      
        // Reverse the entire string to get the final result
        reverse(s.begin(), s.end());
      
        return s;
    }
};