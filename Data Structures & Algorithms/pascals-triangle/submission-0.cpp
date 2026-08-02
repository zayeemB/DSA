class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> tri;
        tri.push_back({1});
        if(numRows == 1) return tri;
        
        tri.push_back({1,1});

        for(int i = 2; i < numRows; i++){
            vector<int> curr;
            vector<int> &prev = tri[i-1];
            curr.push_back(1);
            for(int j = 0; j < prev.size()-1; j++){
                curr.push_back(prev[j]+prev[j+1]);
            }
            curr.push_back(1);
            tri.push_back(curr);
        }
        return tri;
    }
};