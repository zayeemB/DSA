class Solution {
public:
    void sortColors(vector<int>& nums) {
        int map[3] = {0,0,0};
        for(auto &num: nums) map[num]++;
        int idx = 0;
        int i = 0;
        while(map[0] != 0 || map[1] != 0 || map[2] != 0){
            if(map[idx] == 0) idx++;
            else {
                nums[i++] = idx;
                map[idx]--;
            }
        }
    }
};