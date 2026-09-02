class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int minOps = INT_MAX;
        for(int i = 0; i < n-k+1; i++){
            int ops = 0;
            for(int j = i; j < i+k; j++){
                if(blocks[j] == 'W') ops++;
            }
            minOps = min(ops, minOps);
        }
        return minOps;
    }
};