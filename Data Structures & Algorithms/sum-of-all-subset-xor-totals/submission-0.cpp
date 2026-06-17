class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int sums = 0;
        auto generatesubsets = [&](auto &self, int index, int x){
            if(index == nums.size()){
                sums += x;
                return;
            }

            int temp = x;
            x = x^nums[index];
            self(self, index+1, x);
            self(self, index+1, temp);
        };

        generatesubsets(generatesubsets, 0, 0);
        return sums;
    }
};