class Solution {
public:
    int calculate(vector<int> point){
        return point[0] * point[0] + point[1] * point[1];
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> maxHeap; // First = distance ; Second = Coordinates

        for(auto point : points){
            int distance = calculate(point);
            maxHeap.push({distance, point});

            if(maxHeap.size() > k){
                maxHeap.pop();
            }
        }

        vector<vector<int>> result;
        while(!maxHeap.empty()){
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return result;
    }
};