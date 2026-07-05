class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        vector<int> buckets(limit + 1, 0);
        
        for(auto &b: people)
            buckets[b]++;

        int l = 0;
        for(int i = 0; i <= limit; i++){
            while(buckets[i] > 0){
                people[l++] = i;
                buckets[i]--;
            }
        }

        l = 0;
        int r = people.size()-1;
        int boats = 0;
        while(l < r){
            if(people[l] + people[r] <= limit){
                boats++;
                l++;
                r--;
            }
            else{
                r--;
                boats++;
            }
        }
        if(l == r)
            boats++;
        return boats;
    }
};