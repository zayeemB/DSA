class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        int total = 0;

        for(int i = 0; i < grid.size(); i++){
            int count = 0;
            int r, c;

            for(int j = 0; j < grid[0].size(); j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    r = i; c = j;
                    count++;
                    visited[i][j] = true;
                }
            }

            if(count == 1){
                visited[r][c] = false;
            }
            else{
                total += count;
            }
        }

        for(int j = 0; j < grid[0].size(); j++){
            int fresh = 0, stale = 0;

            for(int i = 0; i < grid.size(); i++){
                if(grid[i][j] == 1){
                    stale++;

                    if(!visited[i][j]){
                        fresh++;
                        visited[i][j] = true;
                    }
                }
            }

            if(stale > 1)
                total += fresh;
        }

        return total;
    }
};