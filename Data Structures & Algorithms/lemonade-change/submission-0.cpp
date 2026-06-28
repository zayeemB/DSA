class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int,int, greater<int>> change;
        
        change[5] = 0;
        change[10] = 0;
        change[20] = 0;
        
        for(auto &bill: bills){
            int to_return = bill - 5;

            for(auto &p: change){
                if(p.second == 0 || p.first > to_return) continue;
                while(p.second > 0 && to_return >= p.first) {
                    to_return -= p.first;
                    p.second--;
                }
            }
            
            if(to_return > 0) return false;
            change[bill]++;
        }

        return true;
    }   
};