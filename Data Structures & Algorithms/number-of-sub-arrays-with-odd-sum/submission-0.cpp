class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        unordered_map<long long,int> map; map[0] = 1; 
        long long prefix = 0, count = 0;
        for(int i = 0; i < arr.size(); i++){
            prefix += arr[i];   
            count += map[((prefix % 2)+1)%2];
            map[prefix%2]++;
        }
        int MOD = 1e9 + 7;
        return count % MOD;
    }
};