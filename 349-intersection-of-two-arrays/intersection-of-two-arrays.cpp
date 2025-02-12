class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_set<int> us(nums1.begin(), nums1.end());  // Stores unique element of nums1

        for(auto it : nums2){
            if(us.count(it)){
                ans.push_back(it);
                us.erase(it);   // Ensures uniqueness
            }
        }

        return ans;
    }
};