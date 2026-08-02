class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for(int i = 0; i < flowerbed.size(); i++){
            if(flowerbed[i] == 1) continue;
            else{
                if((i == 0 || flowerbed[i-1] != 1) && (i == flowerbed.size()-1 || flowerbed[i+1] != 1)){ 
                    flowerbed[i] = 1;
                    n--;
                }
            }
        }
        return n <= 0;
    }
};