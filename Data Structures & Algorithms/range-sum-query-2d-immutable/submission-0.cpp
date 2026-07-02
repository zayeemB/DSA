class NumMatrix {
public:
    vector<vector<int>> cumsum;
    NumMatrix(vector<vector<int>>& matrix) {
        cumsum = matrix;
        for(int i = 0; i < cumsum.size(); i++){
            for(int j = 0; j < cumsum[0].size(); j++){
                int top = (i > 0) ? cumsum[i-1][j] : 0;
                int left = (j > 0) ? cumsum[i][j-1] : 0;
                int top_left = (i > 0 && j > 0) ? cumsum[i-1][j-1] : 0;
                
                cumsum[i][j] = cumsum[i][j] + top + left - top_left;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int n = cumsum[row2][col2];
        if(row1 > 0) n -= cumsum[row1-1][col2];
        if(col1 > 0) n -= cumsum[row2][col1-1];
        if(row1 > 0 && col1 > 0) n += cumsum[row1-1][col1-1];
        return n;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */