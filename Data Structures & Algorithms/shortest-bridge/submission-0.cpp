class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        int dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

        queue<pair<int,int>> q;

        for(int i = 0; i < n; i++){
            bool flag = false;

            for(int j = 0; j < m; j++){
                if(grid[i][j] != 1)
                    continue;

                q.push({i,j});
                grid[i][j] = -1;

                while(!q.empty()){
                    auto [r, c] = q.front(); q.pop();

                    for(auto &dir: dirs){
                        int nr = r + dir[0];
                        int nc = c + dir[1];

                        if(
                            nr >= 0 && nr < n &&
                            nc >= 0 && nc < m &&
                            grid[nr][nc] == 1
                        ) {
                            grid[nr][nc] = -1;
                            q.push({nr, nc});
                        }
                    }
                }

                flag = true;
                break;
            }

            if(flag) break;
        }

        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == -1) q.push({i,j});
            }
        }

        vector<vector<int>> dist(n, vector<int>(m, 0));

        while(!q.empty()){
            auto [r, c] = q.front(); q.pop();

            for(auto &dir: dirs){
                int nr = r + dir[0];
                int nc = c + dir[1];

                if(
                    nr >= 0 && nr < n &&
                    nc >= 0 && nc < m
                ) {
                    if(grid[nr][nc] == 1){
                        return dist[r][c];
                    }
                    else if(grid[nr][nc] == 0){
                        dist[nr][nc] = dist[r][c] + 1;
                        grid[nr][nc] = -1;
                        q.push({nr, nc});
                    }
                }
            }
        }

        return 0;
    }
};