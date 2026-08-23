class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int currentNumber = 0;
        char op = '+';

        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            if(isdigit(ch)){
                currentNumber = currentNumber*10 + (ch - '0');
            }

            if((!isdigit(ch) && !isspace(ch)) || i == s.size()-1){
                if(op == '+')
                    st.push(currentNumber);
                else if(op == '-')
                    st.push(-currentNumber);
                else if(op == '/'){
                    int top = st.top(); st.pop();
                    st.push(top/currentNumber);
                }
                else if(op == '*'){
                    int top = st.top(); st.pop();
                    st.push(top*currentNumber);  
                }
                op = ch;
                currentNumber = 0;
            }
        }
        int result = 0;
        while(!st.empty()){
            result += st.top();
            st.pop();
        }
        return result;
    }
};