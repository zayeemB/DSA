class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        struct Node{
            int x, y;
            int effort;

            Node(int x, int y, int effort) : x(x), y(y), effort(effort) {}
        };

        int n = heights.size(), m = heights[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<vector<int>> efforts(n, vector<int>(m, INT_MAX));

        int dirs[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};

        auto comp = [](Node &a, Node &b){
            return a.effort > b.effort;
        };

        priority_queue<Node, vector<Node>, decltype(comp)> q;
        q.push(Node(0,0,0));
        
        efforts[0][0] = 0;

        while(!q.empty()){
            Node curr = q.top(); q.pop();
            int x = curr.x, y = curr.y;
            int effort = curr.effort;

            if(visited[x][y]) continue;
            visited[x][y] = true;

            for(auto &dir: dirs){
                int nx = x + dir[0];
                int ny = y + dir[1];

                if(
                    nx >= 0 && nx < n && ny >= 0 && ny < m
                ){
                    int newEffort = max(effort, abs(heights[nx][ny]-heights[x][y]));
                    if(newEffort < efforts[nx][ny]){
                        efforts[nx][ny] = newEffort;
                        q.push(Node(nx, ny, newEffort));
                    }
                }
            }
        }
        return efforts[n-1][m-1];
    }   
};