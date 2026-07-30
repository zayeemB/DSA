class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();

        vector<vector<int>> board(m, vector<int>(n, 0));

        board[0][0] = (obstacleGrid[0][0] == 1)? 0: 1;

        for(int i = 1; i < m; i++){
            if(obstacleGrid[i][0] == 1) board[i][0] = 0;
            else board[i][0] = board[i-1][0];
        }
        
        for(int j = 1; j < n; j++){ 
            if(obstacleGrid[0][j] == 1) board[0][j] = 0;
            else board[0][j] = board[0][j-1];
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(obstacleGrid[i][j] == 1) board[i][j] = 0;
                else board[i][j] = board[i-1][j] + board[i][j-1];
            }
        }

        return board.back().back();
    }
};