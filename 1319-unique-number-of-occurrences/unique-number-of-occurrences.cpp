class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> ump; // (Element, Frequency)
        for(auto num : arr){
            ump[num]++;
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