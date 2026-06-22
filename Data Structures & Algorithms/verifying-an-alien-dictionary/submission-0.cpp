class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> map;
        for(int i = 0; i < order.size(); i++){
            map[order[i]] = i+1;
        }   
        auto greaterOrder = [&](string &a, string &b)->bool{
            int len = min(a.size(), b.size());
            for(int i = 0; i < len; i++){
                int pos1 = map[a[i]], pos2 = map[b[i]];
                if(pos1 > pos2) return true;
                else if(pos1 < pos2) return false;
            }
            if(a.size() > b.size()) return true;
            else return false;
        };
        for(int i = 0; i < words.size()-1; i++){
            if(greaterOrder(words[i], words[i+1])) return false;
        }
        return true;
    }
};