class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(), false));

        int src = image[sr][sc];

        image[sr][sc] = color;
        q.push({sr,sc});
        visited[sr][sc] = true;

        int dirs[4][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}};

        while(!q.empty()){
            auto [r,c] = q.front(); q.pop();

            for(auto &dir: dirs){
                int nr = r + dir[0];
                int nc = c + dir[1];

                if(
                    nr >= 0 && nr < image.size() &&
                    nc >= 0 && nc < image[0].size() &&
                    !visited[nr][nc] && image[nr][nc] == src
                ){  
                    image[nr][nc] = color;
                    q.push({nr,nc});
                    visited[nr][nc] = true;
                }
            }
        }

        return image;
    }
};