class Solution {
public:
    int compress(vector<char>& chars) {
        int writeIndex = 0;  // Index for writing compressed characters
        int arrayLength = chars.size();
      
        // Iterate through the array using two pointers
        for (int readIndex = 0, nextIndex = readIndex + 1; readIndex < arrayLength;) {
            // Find the end of the current group of consecutive characters
            while (nextIndex < arrayLength && chars[nextIndex] == chars[readIndex]) {
                ++nextIndex;
            }
          
            // Write the character to the compressed position
            chars[writeIndex++] = chars[readIndex];
          
            // If the group has more than one character, write the count
            int groupSize = nextIndex - readIndex;
            if (groupSize > 1) {
                // Convert the count to string and write each digit
                string countStr = to_string(groupSize);
                for (char digit : countStr) {
                    chars[writeIndex++] = digit;
                }
            }
          
            // Move to the next group
            readIndex = nextIndex;
        }
      
        // Return the new length of the compressed array
        return writeIndex;
    }
};