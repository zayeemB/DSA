class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,vector<string>> map;
        unordered_map<string, string> names;

        for(auto &account: accounts){
            if(!map.contains(account[1])) map[account[1]] = vector<string>();
            for(int i = 1; i < account.size(); i++){
                if(i >= 2) {
                    map[account[1]].push_back(account[i]);
                    map[account[i]].push_back(account[1]);
                }
                names[account[i]] = account[0];
            }
        }

        unordered_map<string,bool> visited;
        vector<vector<string>> merged_accounts;

        for(auto &p: map){
            string email = p.first;
            if(visited[email]) continue;

            vector<string> merged_account;
            queue<string> q;

            merged_account.push_back(names[email]);
            merged_account.push_back(email);
            visited[email] = true;
            q.push(email);

            while(!q.empty()){
                string curr_email = q.front(); q.pop();
                for(auto &nei: map[curr_email]){
                    if(!visited[nei]){
                        merged_account.push_back(nei);
                        visited[nei] = true;
                        q.push(nei); 
                    }
                }
            }
            merged_accounts.push_back(merged_account);
        }
        for(auto &merged_account: merged_accounts){
            sort(merged_account.begin()+1, merged_account.end());
        }
        return merged_accounts;
    }
};