class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b){
            string combA = to_string(a)+to_string(b);
            string combB = to_string(b)+to_string(a);
            return combA > combB;
        });
        if (nums[0] == 0) {
            return "0";
        }
        string res = "";
        for(auto num: nums) res += to_string(num);
        return res;
    }
};
