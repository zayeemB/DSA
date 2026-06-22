class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dictSet(wordDict.begin(), wordDict.end());

        vector<vector<string>> sentences;

        auto recurse = [&](auto &self, int index, vector<string> sentence){
            if(index == s.size()){
                sentences.push_back(sentence);
                return;
            }

            for(int i = index; i < s.size(); i++){
                string word = s.substr(index, i-index+1);
                if(dictSet.contains(word)){
                    sentence.push_back(word);
                    self(self, i+1, sentence);
                    sentence.pop_back();
                }
            }
        };

        recurse(recurse, 0, vector<string>());
        
        vector<string> res;

        for(auto &sentence: sentences){
            string strSent = "";
            for(auto &word: sentence){
                strSent += word + " ";
            }
            if (!strSent.empty()) 
                strSent.pop_back();
            res.push_back(strSent);
        }

        return res;
    }
};