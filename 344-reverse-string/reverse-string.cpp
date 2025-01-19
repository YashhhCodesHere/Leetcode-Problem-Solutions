#include <stack>
class Solution {
public:
    // Here, we will use stack for reversing the string!
    void reverseString(vector<char>& s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            st.emplace(s[i]);
        }
        for(int i = 0; i < s.size(); i++){
            s[i] = st.top();
            st.pop();
        }
    }
};