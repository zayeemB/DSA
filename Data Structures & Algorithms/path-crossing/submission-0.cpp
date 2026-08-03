class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int,int>> myset;
        int x = 0, y = 0;
        myset.insert({x,y});
        for(auto &dir: path){
            if(dir == 'N'){
                y+=1;
            }
            else if(dir == 'S'){
                y-=1;
            }
            else if(dir == 'E'){
                x+=1;
            }
            else{
                x-=1;
            }

            if(myset.contains({x,y})) return true;
            myset.insert({x,y});
        }
        return false;
    }
};