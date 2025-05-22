class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> ump;

        for(size_t i = 0; i < nums.size(); i++){
            ump[nums[i]]++;
        }

        for(auto i : ump){
            if(i.second > 1){
                return true;
            }
        }
        return false;
    }
};