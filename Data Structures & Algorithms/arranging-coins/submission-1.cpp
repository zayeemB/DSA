class Solution {
public:
    int arrangeCoins(int n) {
        // Greatest k such that k(k+1)/2 <= n
        int l = 1, r = n;
        // while(l <= r){
        //     long long mid = l + (r-l)/2;
        //     long long rows = (mid * (mid+1))/2;
        //     if(rows == n){
        //         return mid;
        //     }
        //     else if(rows > n){
        //         r = mid - 1;
        //     }
        //     else{
        //         l = mid + 1;
        //     }
        // }
        // return r;

        while(l < r){
            long long mid = l + (r-l)/2;
            long long rows = mid * (mid+1)/2;
            if(rows < n){
                l = mid+1;
            }
            else{
                r = mid;
            }
        }
        return (long long)r*(r+1)/2 == n? r: r-1;
    }
};