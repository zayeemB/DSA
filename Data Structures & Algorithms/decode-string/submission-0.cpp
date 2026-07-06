class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        for(int i = s.size()-1; i >= 0; i--){
            char c = s[i];
            if(c == '['){
                string merged = "";
                while(!st.empty() && st.top() != "]"){
                    merged += st.top(); st.pop();
                }
                st.pop();
                st.push(merged);
            }
            else if(c - '0' >= 0 && c- '0' <= 9){
                int mul = c - '0';
                if(i > 0 && s[i-1] >= '0' && s[i-1] <= '9'){
                    mul += 10 * (s[i-1] - '0');
                    i--;
                    if(i > 0 && s[i-1] >= '0' && s[i-1] <= '9'){
                        mul += 100 * (s[i-1] - '0');
                        i--;
                    }
                }

                cout << mul << endl;

                string multed = "";
                string s = st.top(); st.pop();
                for(int i = 0; i < mul; i++){
                    multed += s;
                }
                st.push(multed);
            }
            else{
                string s = "";
                s += c;
                st.push(s);
            }
        }

        string res = "";
        while(!st.empty()){
            res += st.top(); st.pop();
        }
        return res;
    }
};