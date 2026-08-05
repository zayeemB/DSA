class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> stv(words.size()+1,0);
        unordered_set<char> myset({'a','e','i','o','u'});
        for(int i = 0; i < words.size(); i++){
            string &word = words[i];
            if(myset.contains(word[0]) && myset.contains(word.back())) stv[i+1]=stv[i]+1;
            else stv[i+1] = stv[i];
        }
        vector<int> res;
        for(int i = 0; i < queries.size(); i++){
            vector<int> &query = queries[i];
            res.push_back(stv[query[1]+1] - stv[query[0]]);
        }
        return res;
    }
};