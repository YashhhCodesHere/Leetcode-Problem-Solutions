class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> ump; // (Element, Frequency)
        int n = arr.size();
        for(int i = 0; i < n; i++){
            ump[arr[i]]++;
        }

        unordered_set<int> us;
        for(auto it : ump){
            if(us.insert(it.second).second == 0){
                return false;
            }
        }
        return true;
    }
};