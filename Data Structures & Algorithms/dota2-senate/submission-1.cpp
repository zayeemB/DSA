class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> d;
        queue<int> r;

        int n = senate.size();

        for(int i = 0; i < n; i++){
            if(senate[i] == 'D') d.push(i);
            else r.push(i);
        }   

        while(!r.empty() && !d.empty()){
            if(r.front() < d.front()){
                d.pop();
                int s = r.front(); r.pop();
                r.push(s+n);
            }
            else if(r.front() > d.front()){
                r.pop();
                int s = d.front(); d.pop();
                d.push(s+n);
            }
        }

        if(r.empty()) return "Dire";
        else return "Radiant";
    }
};