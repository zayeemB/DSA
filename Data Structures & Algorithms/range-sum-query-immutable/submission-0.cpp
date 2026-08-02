class NumArray {
public:
    vector<int> prefix;
    NumArray(vector<int>& nums) {
        prefix.push_back(0);
        prefix.insert(prefix.end(), nums.begin(), nums.end());
        for(int i = 1; i < prefix.size(); i++)
            prefix[i] += prefix[i-1];
    }
    
    int sumRange(int left, int right) {
        return prefix[right+1] - prefix[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */