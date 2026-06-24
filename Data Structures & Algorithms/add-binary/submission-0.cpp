class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        if (a.size() < b.size()) {
            a.append(b.size() - a.size(), '0');
        } else if (b.size() < a.size()) {
            b.append(a.size() - b.size(), '0');
        }

        bool ca = 0;

        string res = "";

        for(int i = 0; i < a.size(); i++){
            bool sum = (bool)((a[i]-'0')^(b[i]-'0'))^(ca);
            ca = (bool)((a[i]-'0')&(b[i]-'0'))|(ca&((a[i]-'0')^(b[i]-'0')));
            res.push_back(sum + '0');
        }

        if(ca) res.push_back(ca+'0');
        reverse(res.begin(), res.end());
        return res;
    }
};