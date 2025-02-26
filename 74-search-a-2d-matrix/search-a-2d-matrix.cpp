class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();  // No. of rows
        int n = matrix[0].size();   // No. of cols

        int left = 0, right = m * n - 1;

        while(left <= right){
            int mid = left + (right-left) / 2;

            int row = mid / n;
            int col = mid % n;

            if(matrix[row][col] == target){
                return true;
            }else if(target > matrix[row][col]){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }

        return false;
    }
};