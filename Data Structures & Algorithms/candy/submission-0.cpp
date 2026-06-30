class Solution {
public:
    int candy(vector<int>& ratings) {

        // int n = ratings.size();
        // vector<int> candies(n,1);

        // for(int i = 1; i < n; i++){
        //     if(ratings[i] > ratings[i-1]) {
        //         candies[i] = candies[i-1]+1;
        //     }
        // }

        // for(int i = n-2; i >= 0; i--){
        //     if(ratings[i] > ratings[i+1]){
        //         candies[i] = max(candies[i], candies[i+1]+1);
        //     }
        // }

        // int total = 0;
        // for(auto &c: candies) total+=c;
        // return total;

        int n = ratings.size();
        if(n == 1) return 1;
        vector<int> candies(n,0);

        queue<int> q;
        for(int i = 0; i < n; i++){
            candies[i] = 1;
            if(i == 0){
                if(ratings[i] <= ratings[i+1]) q.push(i);
            }

            else if(i == n-1){
                if(ratings[i] <= ratings[i-1]) q.push(i);
            }

            else if (ratings[i] <= ratings[i-1] && ratings[i] <= ratings[i+1]){
                q.push(i);
            }
        }
        int nei[2] = {1, -1};

        while(!q.empty()){
            int i = q.front(); q.pop();
            for(auto &ne: nei){
                int ni = i + ne;
                if(ni >= 0 && ni < n && ratings[i] < ratings[ni]){
                    candies[ni] = max(candies[ni],candies[i]+1);
                    q.push(ni);
                }
            }
        }

        int total = 0;
        for(auto &c: candies) total += c;
        return total;
    }
};
