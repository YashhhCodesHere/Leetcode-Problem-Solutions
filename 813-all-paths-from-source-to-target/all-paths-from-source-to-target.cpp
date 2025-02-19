class Solution {
public:
    void allPathHelper(int src, int dest, vector<bool>& visited, vector<int>& ans, vector<vector<int>>& paths, vector<vector<int>>& graph){
        ans.push_back(src);
        if(src == dest){
            paths.push_back(ans);
            ans.pop_back();
            return;
        }
        visited[src] = true;
        
        for(auto v : graph[src]){
            if(!visited[v]){
                allPathHelper(v, dest, visited, ans, paths, graph);
            }
        }
        visited[src] = false;
        ans.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int src = 0, n = graph.size();
        int dest = n - 1;
        vector<bool> visited(n, false);
        vector<vector<int>> paths;
        vector<int> ans;
        allPathHelper(src, dest, visited, ans, paths, graph);

        return paths;
    }
};