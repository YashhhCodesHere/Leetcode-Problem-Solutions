class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int duplicateNumber;

        for(size_t i = 0; i < nums.size()-1; i++){
            if(nums[i] == nums[i+1]){
                duplicateNumber = nums[i];
                break;
            }
        }
        return duplicateNumber;
    }
};