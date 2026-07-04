class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int a = 0, b = 0;

        string s = "";

        while(a < word1.size() && b < word2.size()){
            s.push_back(word1[a++]);
            s.push_back(word2[b++]);
        }

        while(a < word1.size()){
            s.push_back(word1[a++]);
        }

        while(b < word2.size()){
            s.push_back(word2[b++]);
        }

        return s;
    }
};