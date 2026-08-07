class Solution {
public:
    int arraySign(vector<int>& nums) {
        int negCount = 0;
        for(auto &n: nums){
            if(n == 0) return 0;
            if(n < 0) negCount++;
        }
        if(negCount % 2==1) return -1;
        return 1;
    }
};