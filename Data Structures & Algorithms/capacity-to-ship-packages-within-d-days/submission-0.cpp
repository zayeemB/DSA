class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        int max_weight = INT_MIN;
        for(auto &weight: weights){
            sum += weight;
            max_weight = max(max_weight, weight);
        }

        auto daysTaken = [&](int capacity){
            int d = 0;
            int load = 0;

            for(int i = 0; i < weights.size(); i++){
                int weight = weights[i];
                if(load + weight > capacity){
                    d++;
                    load = 0;
                }
                load += weight;

                if(i == weights.size()-1)
                    d++;
            }
            return d;
        };

        int l = 1, r = sum;
        while(l <= r){
            int mid = l + (r-l)/2;

            if(mid < max_weight || daysTaken(mid) > days)
                l = mid+1;
            else
                r = mid -1;
        }

        return l;
    }
};