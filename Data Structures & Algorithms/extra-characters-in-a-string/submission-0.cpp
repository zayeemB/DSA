class Solution {
    struct TrieNode{
        TrieNode *children[26] = {nullptr};
        bool isWord = false;
    };

public:
    int minExtraChar(string s, vector<string>& dictionary) {
    //------ Recursion + Memoization ------
        // int n = s.size();
        // vector<int> dp(s.size()+1, -1);
        // dp.back() = 0;
        // unordered_set<string> dictSet(dictionary.begin(), dictionary.end());
        // auto recurse = [&](auto &self, int l)->int{
        //     if(dp[l] != -1) return dp[l];

        //     if(l == n){
        //         return 0;
        //     }
        //     else{
        //         int cost = INT_MAX;
        //         for(int i = l; i < n; i++){
        //             if(dictSet.contains(s.substr(l,i-l+1)))
        //                 cost = min(self(self, i+1), cost);
        //             else cost = min(self(self, i+1) + i-l+1, cost);
        //         }
        //         return dp[l] = cost;
        //     } 
        // };

        // recurse(recurse, 0);
        // return dp[0];

    //------ Trie ------

        TrieNode *trie = new TrieNode();
        for(auto &word: dictionary){
            TrieNode *node = trie;
            for(auto &c: word){
                int idx = c-'a';
                if(node->children[idx] == nullptr){
                    node->children[idx] = new TrieNode();
                }
                node = node->children[idx];
            }
            node->isWord = true;
        }

        int n = s.size();
        vector<int> dp(s.size()+1, -1);
        auto recurse = [&](auto &self, int l)->int{
            if(dp[l] != -1) return dp[l];

            if(l == n){
                return dp[n] = 0;
            }
            else{
                int cost = 1 + self(self, l + 1);
                
                TrieNode *node = trie;
                for(int i = l; i < n; i++){
                    int idx = s[i] - 'a';
                    if(node->children[idx] == nullptr) break;

                    node = node->children[idx];

                    if (node->isWord)
                        cost = min(cost, self(self, i + 1));
                }

                return dp[l] = cost;
            } 
        };

        recurse(recurse, 0);
        return dp[0];

    }
};