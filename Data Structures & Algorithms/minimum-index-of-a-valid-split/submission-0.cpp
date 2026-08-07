class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int i = 0; i < nums.size(); i++) freq[nums[i]]++;
        int dom, domFreq = INT_MIN;
        for(auto &p: freq){
            if(domFreq < p.second){
                domFreq = p.second;
                dom = p.first;
            }
        }
        // vector<int> prefix(nums.size(),0);
        // prefix[0] = (nums[0] == dom)? 1: 0;
        // for(int i = 1; i < nums.size(); i++){
        //     if(nums[i] == dom) prefix[i] = prefix[i-1]+1;
        //     else prefix[i] = prefix[i-1];
        // }
        // vector<int> suffix(nums.size(),0);
        // suffix[nums.size()-1] = (nums[nums.size()-1] == dom)? 1: 0;
        // for(int i = nums.size()-2; i >= 0; i--){
        //     if(nums[i] == dom) suffix[i] = suffix[i+1]+1;
        //     else suffix[i] = suffix[i+1];
        // }
        // for(int i = 0; i < nums.size()-1; i++){
        //     if(prefix[i] > (i+1)/2 && suffix[i+1] > (nums.size()-i-1)/2) return i;
        // }
        // return -1;

        int leftFreq = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == dom) leftFreq++;
            if(leftFreq > (i+1)/2 && domFreq-leftFreq > (nums.size()-i-1)/2) return i;
        }
        return -1;
    }
};