class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string,double>>> adj;

        for(int i = 0; i < equations.size(); i++){
            vector<string> equation = equations[i];
            double weight = values[i];

            adj[equation[0]].push_back({equation[1],weight});
            adj[equation[1]].push_back({equation[0],1/weight});
        } 

        vector<double> output(queries.size(), -1);  

        for(int i = 0; i < queries.size(); i++){
            vector<string> query = queries[i];

            string start = query[0], end = query[1];
            if(!adj.contains(start) || !adj.contains(end)) continue;
            if(start == end) output[i] = 1;

            unordered_map<string,bool> visited;
            queue<pair<string, double>> q;

            visited[start] = true;
            q.push({start, 1});

            while(!q.empty()){
                pair<string, double> curr = q.front(); q.pop();
                bool flag = false;

                for(auto &nei: adj[curr.first]){
                    if(!visited[nei.first]){
                        if(nei.first == end){
                            output[i] = curr.second * nei.second;
                            flag = true;
                            break;
                        }
                        q.push({nei.first, curr.second * nei.second});
                        visited[nei.first] = true;
                    }
                }
                if(flag) break;
            }

        }
        return output;
    }
};