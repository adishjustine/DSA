class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int size1 = word1.size();  // original size of word1
        int size2 = word2.size();  // original size of word2
        int ptr1 = 0;
        int ptr2 = 0;

        // Use current word1.size() in the loop to handle growing string
        while (ptr1 < word1.size() && ptr2 < size2) {
            ptr1++;  // move past current character
            word1.insert(ptr1, 1, word2[ptr2]);  // insert one char from word2
            ptr1++;  // move past inserted char
            ptr2++;
        }

        // Append any leftover characters from word2 if it was longer originally
        if (size2 > size1) {
            word1 += word2.substr(ptr2);
        }

        return word1;
    }
};