class Solution {
public:
    void heapify(int parentIdx, vector<int>& nums, int size){
        int leftChild = (2*parentIdx) + 1;
        int rightChild = (2*parentIdx) + 2;
        int maxIdx = parentIdx;

        if(leftChild < size && nums[leftChild] > nums[maxIdx]){
            maxIdx = leftChild;
        }

        if(rightChild < size && nums[rightChild] > nums[maxIdx]){
            maxIdx = rightChild;    // maxIdx is now one of the child's idx
        }

        if(maxIdx != parentIdx){
            swap(nums[parentIdx], nums[maxIdx]);
            heapify(maxIdx, nums, size);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        // Building the MaxHeap:-
        for(int i = n/2-1; i >= 0; i--){
            heapify(i, nums, n);
        }

        // Sorting:-
        for(int i = n-1; i >= 0; i--){
            swap(nums[0], nums[i]);
            heapify(0, nums, i);
        }

        return nums;
    }
};