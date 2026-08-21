class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> mystack;
        for(auto log: logs){
            if(log == "../") {if(!mystack.empty()) mystack.pop();}
            else if(log == "./") {continue;}
            else {mystack.push(log);}
        }
        return mystack.size();
    }
};