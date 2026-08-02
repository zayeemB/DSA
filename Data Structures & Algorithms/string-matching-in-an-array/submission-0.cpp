class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        auto isSubstr = [](string a, string b){
            if(a.size() > b.size()) return false;
            for(int i = 0; i < b.size()-a.size()+1; i++){
                int j = 0;
                for(j = 0; j < a.size(); j++){
                    if(a[j] != b[i+j]) break;
                }
                if(j == a.size()) return true;
            }
            return false;
        };

        vector<string> res;

        for(int i = 0; i < words.size(); i++){
            for(int j = 0; j < words.size(); j++){
                if(i == j) continue;
                if(isSubstr(words[i], words[j])){
                    res.push_back(words[i]);
                    break;
                }
            }
        }

        return res;
    }
};