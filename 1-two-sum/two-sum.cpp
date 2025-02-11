class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ump;    // (Element, Index)
        int n = nums.size();

        for(int i = 0; i < n; i++){
            int comp = target - nums[i];
            if(ump.count(comp)){
                return {ump[comp], i};
            }
            ump[nums[i]] = i;
        }
        return {};
    }
};

/*
    Brute-Force: Using Nested Loops -> O(n^2)
    Sorting: Using 2-Pointer Approach -> O(nlogn)
    Optimized: Using Hashing(Unordered Map) -> O(n)
*/