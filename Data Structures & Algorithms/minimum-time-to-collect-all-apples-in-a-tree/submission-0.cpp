class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);

        for(auto &edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int time = 0;

        auto dfs = [&](auto &self, int vertex, int parent)->bool{
            bool flag = false;

            if(hasApple[vertex]){
                flag = true;
            }

            for(auto child: adj[vertex]){
                if(child != parent && self(self, child, vertex)){
                    time += 2;
                    flag = true;
                }
            }

            if(flag) return true;
            return false;
        };

        dfs(dfs, 0, -1);

        return time;
    }
};