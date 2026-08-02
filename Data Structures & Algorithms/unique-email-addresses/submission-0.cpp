class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> ms;
        for(auto &email: emails){
            string curr = "";
            int i = 0;
            for(i = 0; i < email.size(); i++){
                char c = email[i];
                if(c == '.') continue;
                if(c == '+'){
                    while(email[i] != '@') i++;
                    break;
                }
                if(c == '@') break;
                curr += c;
            }
            while(i != email.size()){
                curr += email[i++];
            }
            ms.insert(curr);
        }
        return ms.size();
    }
};