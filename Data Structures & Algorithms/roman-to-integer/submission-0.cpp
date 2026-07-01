class Solution {
public:
    int romanToInt(string s) {
        int m[26];

        m['I' - 'A'] = 1;
        m['V' - 'A'] = 5;
        m['X' - 'A'] = 10;
        m['L' - 'A'] = 50;
        m['C' - 'A'] = 100;
        m['D' - 'A'] = 500;
        m['M' - 'A'] = 1000;

        int number = 0;

        number += m[s.back() - 'A'];

        for(int i = s.size()-2; i >= 0; i--){
            if(m[s[i] - 'A'] < m[s[i+1] - 'A'])
                number -= m[s[i] - 'A'];
            else number += m[s[i] - 'A'];
        }

        return number;
    }
};