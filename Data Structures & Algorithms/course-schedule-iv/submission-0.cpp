class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses, vector<int>());
        for(auto &edge: prerequisites){
            adj[edge[0]].push_back(edge[1]);
        }

        vector<bool> ans(queries.size(), false);

        for(int i = 0; i < queries.size(); i++){
            vector<int> query = queries[i];

            vector<bool> visited(numCourses, false);
            int start = query[0], end = query[1];
            
            queue<int> q;
            if(start == end){
                ans[i] = true;
                continue;
            }
            visited[start] = true;
            q.push(start);

            while(!q.empty()){
                int curr = q.front(); q.pop();
                bool flag = false;
                for(auto &nei: adj[curr]){
                    if(!visited[nei]){
                        if(nei == end){
                            ans[i] = true;
                            flag = true;
                            break;
                        }
                        else{
                            visited[nei] = true;
                            q.push(nei);
                        }
                    }
                }
                if(flag) break;
            }
        }
        return ans;
    }
};