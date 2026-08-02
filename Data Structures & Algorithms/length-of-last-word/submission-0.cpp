class Solution {
public:
    int lengthOfLastWord(string s) {
        int size = 0;
        int l = 0, r = s.size()-1;

        while(s[l] == ' ') l++;
        while(s[r] == ' ') r--;

        for(int i = r; i >= l; i--){
            if(s[i] == ' ') break;
            size++;
        }
        return size;
    }
};