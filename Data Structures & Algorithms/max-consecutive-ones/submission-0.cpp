class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxN = INT_MIN;
        int maxC = 0;
        nums.push_back(0);
        for(auto &num: nums){
            if(num == 0) maxC = 0;
            else maxC++;
            maxN = max(maxN, maxC);
        }
        return maxN;
    }
};