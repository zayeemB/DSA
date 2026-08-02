class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> prefix, suffix = nums;
        prefix.push_back(0);
        prefix.insert(prefix.end(), nums.begin(), nums.end());
        for(int i = 1; i < prefix.size(); i++)
            prefix[i] += prefix[i-1];

        for(int i = nums.size()-2; i >= 0; i--)
            suffix[i] += suffix[i+1];
        suffix.push_back(0);

        for(int i = 0; i < nums.size(); i++){
            if(prefix[i] == suffix[i+1]) return i;
        }

        return -1;
    }
};