class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadendSet(deadends.begin(), deadends.end());

        unordered_map<string,bool> visited;

        int depth = 0;

        queue<string> q;
        visited["0000"] = true;
        if(target == "0000") return 0;
        
        if(!deadendSet.contains("0000")) q.push("0000");

        while(!q.empty()){
            int level = q.size();
            depth++;
            for(int i = 0; i < level; i++){
                string combination = q.front(); q.pop();
                for(int i = 0; i < 4; i++){
                    string nei[2];
                    nei[0] = combination, nei[1] = nei[0];

                    nei[0][i] = (nei[0][i] == '9') ? '0' : nei[0][i] + 1;
                    nei[1][i] = (nei[1][i] == '0') ? '9' : nei[1][i] - 1;

                    for(auto & n: nei){
                        if(!deadendSet.contains(n) && !visited[n]){
                            if(n == target) return depth;
                            else {
                                q.push(n);
                                visited[n] = true;
                            }
                        }
                    }
                }
            }
        }
        return -1;
    }
};