class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0, r = 0;
        map<int, int> types;
        int maxFruits = INT_MIN;
        while(r < fruits.size()){
            types[fruits[r]]++;
            while(l < r && types.size() > 2){
                types[fruits[l]]--;
                if(types[fruits[l]]==0)
                    types.erase(fruits[l]);
                l++;
            }
            maxFruits = max(maxFruits, r-l+1);
            r++;
        }
        return maxFruits;
    }
};