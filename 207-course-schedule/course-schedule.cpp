class Solution {
public:
    bool isCyclicUtil(int src, unordered_map<int, bool>& visited, unordered_map<int, bool> instack, vector<vector<int>>& l){
        visited[src] = true;
        instack[src] = true;

        for(auto v : l[src]){
            if(!visited[v] && isCyclicUtil(v, visited, instack, l)){
                return true;
            }else if(instack[v]){
                return true;
            }
        }
        instack[src] = false;
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        for(auto edge : prerequisites){
            adj[edge[1]].push_back(edge[0]);
        }


        unordered_map<int, bool> visited;
        unordered_map<int, bool> instack;

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                if(isCyclicUtil(i, visited, instack, adj)){
                    return false;
                }
            }
        }
        return true;
    }
};