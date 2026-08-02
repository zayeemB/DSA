class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int currMax = -1;
        vector<int> res(arr.size());
        for(int i = arr.size()-1; i >= 0; i--){
            res[i] = currMax;
            currMax = max(currMax, arr[i]);
        }
        return res;
    }
};