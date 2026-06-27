class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int min_size = INT_MAX;
        for(auto &str: strs) {
            min_size = std::min(min_size, (int)str.size());
        }

        string s = "";

        for(int i = 0; i < min_size; i++){
            for(int j = 0; j < strs.size()-1; j++){
                if(strs[j][i] != strs[j+1][i]) return s;
            }
            s += strs[0][i];
        }

        return s;
    }
};