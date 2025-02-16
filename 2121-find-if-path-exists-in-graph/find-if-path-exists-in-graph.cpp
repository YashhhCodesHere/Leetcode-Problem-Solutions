class Solution {
public:
    bool dfs(int source, unordered_map<int, vector<int>>& l, unordered_set<int>& visited, int destination){
        if(source == destination){
            return true;
        }
        visited.insert(source);

        for(auto neighbor : l[source]){
            if(visited.count(neighbor) == 0){
                if(dfs(neighbor, l, visited, destination)){
                    return true;
                }
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> l;  // Adjacency list 

        for(auto edge : edges){     // Building list
            l[edge[0]].push_back(edge[1]);
            l[edge[1]].push_back(edge[0]);
        }

        unordered_set<int> visited;
        return dfs(source, l, visited, destination);
    }
};