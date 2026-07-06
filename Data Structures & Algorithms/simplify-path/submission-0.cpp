class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dirs;

        int l = 0;
        for(int i = 0; i < path.size(); i++){
            char c = path[i];
            if(c == '/'){
                dirs.push_back(path.substr(l, i-l));
                l = i+1;
            }
            else if(i == path.size()-1)
                dirs.push_back(path.substr(l, i-l+1));
        }

        vector<string> st;
        for(auto &dir: dirs){
            if(dir == ".."){
                if(!st.empty()) st.pop_back();
            }
            else if(dir == "." || dir == "")
                continue;
            else
                st.push_back(dir);
        }
        
        string p = "";
        for(auto dir: st){
            p += "/";
            p += dir;
        }

        if(st.size() == 0)
            p += "/";
        
        return p;
    }
};