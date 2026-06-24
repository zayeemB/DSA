class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dictSet(wordList.begin(), wordList.end());

        if(!dictSet.contains(endWord)) return 0;

        queue<pair<string, int>> q;

        q.push({beginWord, 1});

        while(!q.empty()){
            pair<string, int> p = q.front(); q.pop();
            string word = p.first;
            int depth = p.second;

            for(int i = 0; i < beginWord.size(); i++){
                for(char c = 'a'; c <= 'z'; c++){
                    string nei = word;
                    nei[i] = c;

                    if(dictSet.contains(nei)){
                        if(nei == endWord) return depth+1;
                        dictSet.erase(nei);
                        q.push({nei, depth+1});
                    }
                }
            }
        }
        return 0;
    }
};