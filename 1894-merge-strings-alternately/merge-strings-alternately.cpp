class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string word = "";
        int i = 0, j = 0;
        while(i < word1.size() && j < word2.size()){
            word += (word1[i++]);
            word += (word2[j++]);
        }
        while(i < word1.size()){
            word += (word1[i++]);
        }
        while(j < word2.size()){
            word += (word2[j++]);
        }
        return word;
    }
};