class Solution {
public:
    // Here, we'll solve it with recursive approach:-
    int recursiveBinarySearch(vector<int> nums, int left, int right, int target){
        if(left > right){
            return -1;
        }

        int mid = left + (right - left) / 2;
        
        if(nums[mid] == target){
            return mid;
        }
        if(target < nums[mid]){
            return recursiveBinarySearch(nums, left, (mid - 1), target);
        }else{
            return recursiveBinarySearch(nums, (mid + 1), right, target);
        }
    }
    int search(vector<int>& nums, int target) {
        return recursiveBinarySearch(nums, 0, nums.size() - 1, target);
    }
};