class Solution {
public:
    int mySqrt(int x) {
        int l = 1, r = x;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(pow(mid,2) > x)
                r = mid-1;
            else if(pow(mid,2) < x)
                l = mid+1;
            else
                return mid;
        }
        return l-1;
    }
};