class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(auto &operation: operations){
            if(operation == "D"){
                int prev = st.top();
                st.push(2*prev);
            }
            else if(operation == "C"){
                st.pop();
            }
            else if(operation == "+"){
                int prev1 = st.top(); st.pop();
                int prev2 = st.top();
                st.push(prev1);
                st.push(prev1+prev2);
            }
            else{
                st.push(stoi(operation));
            }
        }
        int score = 0;
        while(!st.empty()){
            score += st.top(); st.pop();
        }
        return score;
    }
};