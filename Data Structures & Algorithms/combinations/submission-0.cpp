class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> combinations;

        auto backtrack = [&](auto &self, int index, vector<int> &comb){
            if(comb.size() == k){
                combinations.push_back(comb);
                return;
            }

            if(index > n)
                return;

            comb.push_back(index);
            self(self, index+1, comb);
            comb.pop_back();
            self(self, index+1, comb);
        };

        vector<int> comb;
        backtrack(backtrack, 1, comb);

        return combinations;  
    }
};