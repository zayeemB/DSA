class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(), s.end(), greater<int>());
        sort(g.begin(), g.end(), greater<int>());
        int count = 0, l = 0;
        for(int i = 0; i < g.size(); i++){
            if(l < s.size() && s[l] >= g[i]){
                count++;
                l++;
            }
        }
        return count;
    }
};