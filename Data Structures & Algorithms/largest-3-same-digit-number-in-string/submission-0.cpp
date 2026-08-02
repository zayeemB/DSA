class Solution {
public:
    string largestGoodInteger(string num) {
        int currMax = INT_MIN;
        string res = "";
        for(int i = 0; i < num.size()-2; i++){
            string n = num.substr(i, 3);
            if(n[0] == n[1] && n[1] == n[2] && currMax < stoi(n)){
                currMax =  stoi(n);
                res = n;
            }
        }
        return res;
    }
};