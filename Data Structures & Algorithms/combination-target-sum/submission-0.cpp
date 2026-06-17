class Solution {
    int sum;
    int target;
    vector<vector<int>> res;
    vector<int> combi;

    void recursiveComination(vector<int>& candidates, int index) {
        if(sum > target) {
            return;
        }
        
        else if(sum == target) {
            res.push_back(combi);
            return;
        }

        for(int i = index; i < candidates.size(); i++) {
            sum += candidates[i];
            combi.push_back(candidates[i]);
            recursiveComination(candidates, i);
            combi.pop_back();
            sum -= candidates[i];
        }
    }

 public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sum = 0;
        this->target = target;
        recursiveComination(candidates, 0);
        return res;
    }
};