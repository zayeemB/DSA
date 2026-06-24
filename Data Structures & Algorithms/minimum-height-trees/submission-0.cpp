class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        if (n == 1) return {0};

        vector<int> degree(n, 0);
        vector<vector<int>> adj(n, vector<int>());

        int nodes = n;

        for(auto &edge: edges){
            degree[edge[0]]++;
            degree[edge[1]]++;

            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        queue<int> q;

        for(int i = 0; i < n; i++){
            if(degree[i] == 1) {
                q.push(i);
                degree[i]--;
            }
        }

        while(nodes > 2){
            int levelSize = q.size();
            nodes -= levelSize;

            for(int i = 0; i < levelSize; i++){
                int curr = q.front(); q.pop();

                for(auto &nei: adj[curr]){
                    degree[nei]--;
                    if(degree[nei] == 1){
                        q.push(nei);
                    }
                }
            }
        }

        vector<int> res;
        while(!q.empty()){res.push_back(q.front()); q.pop();}
        return res;
    }
};
