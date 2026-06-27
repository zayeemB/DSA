class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<long long> rooms(n);
        vector<bool> is_occupied(n ,false);

        auto comp = [](pair<long long,long long> a, pair<long long,long long> b){
            if (a.first == b.first) return a.second > b.second; 
            return a.first > b.first;
        };

        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<>> start_times;
        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, decltype(comp)> end_times;
        priority_queue<long long, vector<long long>, greater<>> free_rooms;

        for(auto &meeting: meetings){
            start_times.push({meeting[0], meeting[1]});
        }

        for(long long i = 0; i < n; i++) free_rooms.push(i);

        long long time = 0;

        while(!start_times.empty() || !end_times.empty()){
            
            if (!start_times.empty() && !end_times.empty() && 
                time != start_times.top().first && time != end_times.top().first) {
                
                time = min(start_times.top().first, end_times.top().first);
            }
          
            else if (!start_times.empty() && end_times.empty() && 
                time != start_times.top().first) {
                
                time = start_times.top().first;
            }

            else if (start_times.empty() && !end_times.empty() && 
                time != end_times.top().first) {
                
                time = end_times.top().first;
            }

            while(!end_times.empty() && time == end_times.top().first){
                pair<long long,long long> p = end_times.top(); end_times.pop();
                free_rooms.push(p.second);
            }

            while(!start_times.empty() && time == start_times.top().first){
                if(!free_rooms.empty()){
                    long long ridx = free_rooms.top(); free_rooms.pop();
                    end_times.push({start_times.top().second, ridx}); start_times.pop();
                    rooms[ridx]++;
                }
                else{
                    pair<long long,long long> meeting = start_times.top(); start_times.pop();

                    long long duration = meeting.second - meeting.first;

                    meeting.first = end_times.top().first + duration;
                    meeting.second = end_times.top().second;

                    end_times.pop(); 
                    end_times.push(meeting);
                    rooms[meeting.second]++;
                }
            }

            time++;
        }

        long long max = 0, idx = 0;
        for(long long i = 0; i < n; i++){
            if(max < rooms[i]){
                max = rooms[i];
                idx = i;
            }
        }
        return (int) idx;
    }
};