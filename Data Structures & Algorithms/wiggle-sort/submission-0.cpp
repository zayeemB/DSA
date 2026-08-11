class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> increasing = nums;
        sort(increasing.begin(), increasing.end());
        bool flag = true; int l = 0, r = nums.size()-1;
        for(int i = 0; i < nums.size(); i++){
            if(flag){
                nums[i] = (increasing[l++]);
                flag = !flag;
            }
            else{
                nums[i] = (increasing[r--]);
                flag = !flag;
            }
        }
    }
};
