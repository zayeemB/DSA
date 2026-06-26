class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        struct Trip{
            int passengers;
            int from;
            int to;

            Trip(int p, int s, int e){
                passengers = p;
                from = s;
                to = e;
            }
        };

        auto compa = [](Trip a, Trip b){
            return a.from > b.from;
        };

        auto compb = [](Trip a, Trip b){
            return a.to > b.to;
        };

        priority_queue<Trip, vector<Trip>, decltype(compa)> pqa;
        priority_queue<Trip, vector<Trip>, decltype(compb)> pqb;

        for(auto &trip: trips){
            pqa.push(Trip(trip[0], trip[1], trip[2]));
        }

        int filled = 0;
        int distance = 0;

        while(!pqa.empty() || !pqb.empty()){
            if((!pqa.empty() && !pqb.empty()) && pqa.top().from != distance && pqb.top().to != distance){
                distance = min(pqa.top().from, pqb.top().to);
            }

            while(!pqb.empty() && pqb.top().to == distance){
                filled -= pqb.top().passengers; pqb.pop();
            }

            while(!pqa.empty() && pqa.top().from == distance){
                if(pqa.top().passengers + filled <= capacity){
                    filled += pqa.top().passengers;
                    pqb.push(pqa.top()); pqa.pop();
                }
                else{
                    return false;
                }
            }

            distance++;
        }

        return true;
    }
};