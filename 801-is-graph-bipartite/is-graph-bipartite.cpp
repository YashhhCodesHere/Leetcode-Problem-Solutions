class Solution {
public:
    bool isBipartiteUtil(int src, vector<vector<int>>& graph, vector<int>& color){
        queue<int> q;

        q.push(src);
        color[src] = 0;

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(auto v : graph[curr]){
                if(color[v] == -1){
                    color[v] = !color[curr];
                    q.push(v);
                }else if(color[v] == color[curr]){
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for(int i = 0; i < n; i++){
            if(color[i] == -1){
                if(!isBipartiteUtil(i, graph, color)){
                    return false;
                }
            }
        }
        return true;
    }
};