class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> ump;    //(Element, Frequency)
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(ump.count(nums[i]) == 0){
                ump[nums[i]] = 1;
            }else{
                ump[nums[i]]++;
            }
        }

        for(auto it : ump){
            if(it.second > (n/2)){
                return it.first;
            }
        }
        return 0;
    }
};