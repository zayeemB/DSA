class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;

        int l = 0, r = 0;
        int window = INT_MIN;

        while(r < s.size()){
            if(set.contains(s[r])){
                while(set.contains(s[r])){
                    set.erase(s[l]);
                    l++;
                }
            }
            set.insert(s[r]);
            window = max(window, r-l+1);
            r++;
        }
        return window == INT_MIN? 0: window;
    }
};
