/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        int l = 1, r = n - 2;
        while (l != r) {
            int mid = l + (r - l) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                l = mid + 1;
            } else {
                r = mid;    
            }
        }
        int peak = l;

        l = 0, r = peak;
        while(l <= r){
            int mid = l + (r-l)/2;
            int midVal = mountainArr.get(mid);

            if(midVal < target)
                l = mid+1;
            else 
                r = mid-1;
        }

        if(mountainArr.get(l) == target)
            return l;

        l = peak+1, r = n-1;
        while(l <= r){
            int mid = l + (r-l)/2;
            int midVal = mountainArr.get(mid);
            if(midVal <= target)
                r = mid-1;
            else 
                l = mid+1;
        }

        if(mountainArr.get(l%mountainArr.length()) == target)
            return l;

        return -1;
    }   
};