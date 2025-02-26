class Solution {
public:
    int maxAbsoluteSum(vector<int>& arr) {
        int maxSum = 0, minSum = 0;
        int currMax = 0, currMin = 0;
        for(auto i : arr){
            currMax = max(i, currMax+i);
            maxSum = max(maxSum, currMax);

            currMin = min(i, currMin+i);
            minSum = min(currMin, minSum);
        }
        return max(maxSum, abs(minSum));
    }
};