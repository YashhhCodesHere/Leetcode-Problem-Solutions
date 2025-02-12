class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode(){
        isEndOfWord = false;
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

        for(auto ch : word){
            if(temp->children.find(ch) == temp->children.end()){
                temp->children[ch] = new TrieNode();
            }
            temp = temp->children[ch];
        }

        temp->isEndOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* temp = root;

        for(auto ch : word){
            if(temp->children.count(ch) == 0){
                return false;
            }
            temp = temp->children[ch];
        }
        return temp->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* temp = root;

        for(auto ch : prefix){
            if(temp->children.count(ch) == 0){
                return false;
            }
            temp = temp->children[ch];
        }

        return true;    // Prefix exists, return true even if it's not an end of a word
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */