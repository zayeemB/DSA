class Solution {
public:
    int totalNQueens(int n) {
        vector<bool> cols(n, false);
        vector<bool> diag1(2*n-1, false);
        vector<bool> diag2(2*n-1, false);

        int count = 0;

        auto recurse = [&](auto &self, int row){
            if(row == n){
                count++;
                return;
            }

            for(int j = 0; j < n; j++){
                if(cols[j] || diag1[j+row] || diag2[row-j+n-1]) continue;
                cols[j] = diag1[j+row] = diag2[row-j+n-1] = true;
                self(self, row+1);
                cols[j] = diag1[j+row] = diag2[row-j+n-1] = false;
            }
        };

        recurse(recurse, 0);
        return count;
    }
};