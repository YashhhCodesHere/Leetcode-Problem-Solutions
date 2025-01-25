class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26] = {0};
        queue<char> q;
        int n = s.size();
        for(int i = 0; i < n; i++){
            char ch = s[i];
            freq[ch - 'a']++;
            q.push(ch);
        }
        int idx = 0;
        while(!q.empty()){
            if(freq[q.front() - 'a'] != 1){
                q.pop();
                idx++;
            }else{
                return idx;
            }
        }
        return -1;
    }
};