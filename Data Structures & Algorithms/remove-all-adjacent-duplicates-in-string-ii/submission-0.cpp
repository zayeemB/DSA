class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            if(st.empty() || st.top().first != c){
                st.push({c, 1});
            }
            else if(st.top().second == k-1){
                st.pop();
            }
            else{
                st.top().second++;
            }
        }
        string res = "";
        while(!st.empty()){
            for(int i = 0; i < st.top().second; i++){
                res += st.top().first;
            }
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};