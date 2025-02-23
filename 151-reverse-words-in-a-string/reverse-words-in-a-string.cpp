class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        stringstream ss(s);
        string word;
        string result = "";

        while(ss >> word){
            st.push(word);
        }

        while(!st.empty()){
            result += st.top();
            st.pop();
            if(st.size() != 0){
                result += " ";
            }
        }
        return result;
    }
};