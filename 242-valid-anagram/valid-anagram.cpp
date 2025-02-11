class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        unordered_map<char, int> ump; //(Char, frequency)
        int n = s.size();
        for(auto i = 0; i < n; i++){
            ump[s[i]]++;
            ump[t[i]]--;
        }

        for(auto it : ump){
            if(it.second != 0){
                return false;
            }
        }
        return true;
    }
};