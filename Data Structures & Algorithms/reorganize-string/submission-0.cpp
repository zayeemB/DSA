class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> m;
        for(auto &c: s){
            m[c]++;
        }

        auto comp = [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second < b.second; 
        };
        
        priority_queue<pair<char,int>, vector<pair<char,int>>, decltype(comp)> pq;

        for(auto p: m){
            pq.push(p);
        }

        string out = "";

        while(!pq.empty()){
            if(!out.empty() && pq.top().first == out.back()){
                pair<char,int> t = pq.top(); pq.pop();
                if(!pq.empty()){
                    out.push_back(pq.top().first);
                    if(pq.top().second == 1)
                        pq.pop();
                    else{
                        pair<char, int> p = pq.top(); pq.pop();
                        p.second--;
                        pq.push(p);
                    }
                }
                else { return "";}
                pq.push(t);
            }
            else{
                out.push_back(pq.top().first);
                if(pq.top().second == 1)
                    pq.pop();
                else{
                    pair<char, int> p = pq.top(); pq.pop();
                    p.second--;
                    pq.push(p);
                }
            }
        }
        return out;
    }
};