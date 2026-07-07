class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int largest = INT_MIN;
        for(auto pile: piles){
            largest = max(largest, pile);
        }


        int l = 1, r = largest;

        while(l <= r){
            int mid = l + (r-l)/2;

            long long time = 0;
            for(auto pile: piles){
                time += (pile + mid - 1) / mid;
            }

            if(time <= h)
                r = mid-1;
            else if(time > h)
                l = mid+1;
        }
        return l;
    }
};