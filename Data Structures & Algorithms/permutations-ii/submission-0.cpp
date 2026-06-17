class Solution {
    void backtrack(int index, vector<int> &permut, vector<bool> &used, vector<vector<int>> &permuts, vector<int>& nums){
        if(permut.size() == nums.size()){
            permuts.push_back(permut);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(used[i]) continue;
            if(i < nums.size()-1 && nums[i] == nums[i+1] && !used[i+1]) continue;
            permut.push_back(nums[i]);
            used[i] = true;
            backtrack( i+1, permut, used, permuts, nums);
            used[i] = false;
            permut.pop_back();
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        vector<vector<int>> permuts;
        
        sort(nums.begin(), nums.end());
        vector<int> permut;
        backtrack(0, permut, used, permuts, nums);
        return permuts;
    }
};