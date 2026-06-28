class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {

        vector<pair<int,int>> query_indices;
        for(int i = 0; i < queries.size(); i++){
            query_indices.push_back({queries[i], i});
        }

        sort(query_indices.begin(), query_indices.end());

        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
            return a[0] < b[0];
        });

        auto comp = [](pair<int,int> &a, pair<int,int> &b){
            return a.second - a.first > b.second - b.first;
        };

        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> pq;
        vector<int> answers(queries.size(), INT_MIN);

        int interval_idx = 0;

        for(auto &query_pair: query_indices){
            int query = query_pair.first;
            int query_index = query_pair.second;

            while (interval_idx < intervals.size() && intervals[interval_idx][0] <= query) {
                pq.push({intervals[interval_idx][0], intervals[interval_idx][1]});
                interval_idx++;
            }

            while(!pq.empty() && pq.top().second < query)
                pq.pop();
            
            if(!pq.empty()) answers[query_index] = pq.top().second - pq.top().first +1;
            else answers[query_index] = -1;
        }

        return answers;
    }
};