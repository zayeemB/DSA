class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, int> map;
        int length = -1;
        for(int i = 0; i < s.size(); i++){
            if(map.contains(s[i])) length = max(length, i-map[s[i]]-1);
            else map[s[i]] = i;
        }
        return length;
    }
};