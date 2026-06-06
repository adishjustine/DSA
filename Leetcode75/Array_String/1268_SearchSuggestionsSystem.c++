class Trie {
public:
    /**
     * Insert a word into the trie with its index in the products array
     * At each node, store up to 3 product indices (lexicographically smallest)
     * @param word: the product word to insert
     * @param productIndex: the index of this product in the sorted products array
     */
    void insert(string& word, int productIndex) {
        Trie* currentNode = this;

        // Traverse each character in the word
        for (int charPos = 0; charPos < word.size(); ++charPos) {
            int charIndex = word[charPos] - 'a';

            // Create new node if path doesn't exist
            if (!currentNode->children[charIndex]) {
                currentNode->children[charIndex] = new Trie();
            }

            // Move to next node
            currentNode = currentNode->children[charIndex];

            // Store up to 3 product indices at this node
            if (currentNode->productIndices.size() < 3) {
                currentNode->productIndices.push_back(productIndex);
            }
        }
    }

    /**
     * Search for suggestions for each prefix of the search word
     * @param searchWord: the word to search for
     * @return: a 2D vector where ans[i] contains product indices for prefix searchWord[0..i]
     */
    vector<vector<int>> search(string& searchWord) {
        Trie* currentNode = this;
        int wordLength = searchWord.size();
        vector<vector<int>> suggestions(wordLength);

        // For each character in searchWord, find matching products
        for (int charPos = 0; charPos < searchWord.size(); ++charPos) {
            int charIndex = searchWord[charPos] - 'a';

            // If no matching path exists, remaining suggestions will be empty
            if (!currentNode->children[charIndex]) {
                break;
            }

            // Move to next node and get its stored product indices
            currentNode = currentNode->children[charIndex];
            suggestions[charPos] = move(currentNode->productIndices);
        }

        return suggestions;
    }

private:
    // Array of 26 pointers for each lowercase letter
    vector<Trie*> children = vector<Trie*>(26);

    // Stores up to 3 product indices at this node
    vector<int> productIndices;
};

class Solution {
public:
    /**
     * Find suggested products for each prefix of searchWord
     * Returns at most 3 lexicographically smallest products for each prefix
     * @param products: list of available products
     * @param searchWord: the word being typed/searched
     * @return: suggestions for each prefix of searchWord
     */
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        // Sort products lexicographically
        sort(products.begin(), products.end());

        // Build trie with all products
        Trie* trie = new Trie();
        for (int i = 0; i < products.size(); ++i) {
            trie->insert(products[i], i);
        }

        // Get suggestions for each prefix of searchWord
        vector<vector<string>> result;
        vector<vector<int>> suggestionIndices = trie->search(searchWord);

        // Convert product indices back to product names
        for (auto& indices : suggestionIndices) {
            vector<string> suggestions;
            for (int index : indices) {
                suggestions.push_back(products[index]);
            }
            result.push_back(move(suggestions));
        }

        return result;
    }
};
