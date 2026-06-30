class Solution {
public:
    string convertToTitle(int columnNumber) {
        string s = "";
        while(columnNumber > 0){
            columnNumber--;
            int remainder = columnNumber % 26;
            columnNumber /= 26;
            char c = remainder + 'A';
            s.push_back(c);
        }
        reverse(s.begin(), s.end());
        return s;
    }
};