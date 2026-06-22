class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> pointeeCount(n+1, 0);
        vector<int> pointerCount(n+1, 0);
        for(auto &edge: trust){
            pointeeCount[edge[1]]++;
            pointerCount[edge[0]]++;
        }

        for(int i = 1; i <= n; i++){
            if(pointeeCount[i] == n-1 && pointerCount[i] == 0) return i;
        }

        return -1;
    }
};