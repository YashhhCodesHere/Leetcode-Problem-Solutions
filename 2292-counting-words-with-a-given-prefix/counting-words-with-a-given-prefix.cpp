class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
    int prefixCount; // Tracks number of words sharing this prefix

    TrieNode() {
        isEndOfWord = false;
        prefixCount = 0;
    }
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* temp = root;

        for (char ch : word) {
            if (temp->children.count(ch) == 0) {
                temp->children[ch] = new TrieNode();
            }
            temp = temp->children[ch];
            temp->prefixCount++; // Increase count for this prefix
        }
        temp->isEndOfWord = true;
    }

    int countPrefix(string pref) {
        TrieNode* temp = root;
        
        for (char ch : pref) {
            if (temp->children.find(ch) == temp->children.end()) {
                return 0; // Prefix not found
            }
            temp = temp->children[ch];
        }
        return temp->prefixCount; // Return count of words with this prefix
    }
};

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        Trie trie;
        for (const string& word : words) {
            trie.insert(word);
        }
        return trie.countPrefix(pref);
    }
};