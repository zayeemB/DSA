class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<long long,int> frequency;
        int n = wall.size();
        for(int i = 0; i < n; i++){
            long long current_position = 0;
            for(int j = 0; j < wall[i].size()-1; j++){
                current_position += wall[i][j];
                frequency[current_position]++;
            }
        }
        int maxEdges = INT_MIN;
        for(auto &p: frequency)
            maxEdges = max(p.second, maxEdges);
        return maxEdges == INT_MIN? n: n - maxEdges;
    }
};