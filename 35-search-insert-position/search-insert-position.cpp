class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2; // Correct mid calculation

            if (nums[mid] == target) {
                return mid; // Target found
            } else if (target < nums[mid]) {
                end = mid - 1; // Move end to the left of mid
            } else {
                start = mid + 1; // Move start to the right of mid
            }
        }

        // If target is not found, start is the insert position
        return start;
    }
};
