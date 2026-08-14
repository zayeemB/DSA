class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int l = 0;
        string numString = "";
        for(int i = 0; i < abbr.size(); i++){
            if(isdigit(abbr[i])){
                numString += abbr[i];
            }
            else{
                if (!numString.empty()) {
                    if (numString[0] == '0') return false; 
                    l += stoi(numString);
                    numString = "";
                }
                if(l >= word.size()) return false;
                if(word[l] != abbr[i]) return false;
                l++;
            }
        }
        if (!numString.empty()) {
            if (numString[0] == '0') return false; 
            l += stoi(numString);
        }
        
        return l == word.size();
    }
};