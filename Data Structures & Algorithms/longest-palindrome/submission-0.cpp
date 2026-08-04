class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> map;
        for(auto c: s) map[c]++;
        int length = 0;
        bool flag = true;
        for(auto &p: map){
            if(p.second%2==0) length+=p.second;
            else {length+=p.second-1; if(flag){length++;flag=false;}}
        }
        return length;
    }
};