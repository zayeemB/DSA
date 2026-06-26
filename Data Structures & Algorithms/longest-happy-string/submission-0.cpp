class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        auto comp = [](pair<char,int> a, pair<char,int> b){
            return a.second < b.second;
        };

        priority_queue<pair<char,int>, vector<pair<char,int>>, decltype(comp)> pq;

        if(a != 0) pq.push({'a', a});
        if(b != 0) pq.push({'b', b});
        if(c != 0) pq.push({'c', c});

        string s = "";

        while(!pq.empty()){
            if(!s.empty() && s.back() == pq.top().first && s[s.size()-2] == pq.top().first){
                pair<char,int> p1 = pq.top(); pq.pop();

                if(!pq.empty()){
                    pair<char,int> p2 = pq.top(); pq.pop();
                    s.push_back(p2.first);
                    p2.second--;
                    if(p2.second != 0) {pq.push(p2);}
                }
                else {return s;}
                pq.push(p1);
            } 
            else{
                pair<char,int> p = pq.top(); pq.pop();
                int m = min(2, p.second);
                for(int i = 0; i < m ; i++){
                    s.push_back(p.first);
                    p.second--;
                }
                if(p.second != 0) pq.push(p);
            }  
        }

        return s;

    }
};