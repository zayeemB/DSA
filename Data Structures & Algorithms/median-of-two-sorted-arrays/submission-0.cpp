class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /*
            The median of a sorted array should satify these conditions:
                - It is firstly larger than all elements to the left of it.
                - Smaller than all the elements to the right of it.
                - The number of elements to the left is equal to the number 
                  of elements to the right.

            Supppose we choose some candidate at index i1 of nums1 to be our median.
            Then naturally all the elements to the left of this index in nums1 would
            be to the left of it in the combined array as well and the same with the 
            elements to the right of it. This implies, since there are i1 elements to the
            left of the index (since the array is 0 indexed), that we require (n+m)/2 - i1 
            more elements that are strictly less than nums1[i1] for the index i1 to be a
            valid median. Consequently we require (m+n)/2 - (n-i1-1) elements to that
            are greater than nums1[i1] as well.

            Therefore we choose an index i1 and check its correconding index in nums2
            that results in an equal division of the combined array and check whether
            that satisfies the inequality conditions. If they do, then nums1[i1] must 
            be the median and if they don't we have to find a different number.
        */


        int n = nums1.size(), m = nums2.size();
        int half = (m+n)/2 + (m+n)%2;

        if (n > m) {
            // Swap the arrays to ensure nums1 is always the smaller one
            return findMedianSortedArrays(nums2, nums1); 
        }

        int l = -1, r = n-1;

        while(l < r){
            int i = l + (r-l)/2;
            int j = half-(i+1)-1;

            cout << i << " " << j << endl;

            int left1 = (i==-1)? INT_MIN: nums1[i];
            int right1 = (i==n-1)? INT_MAX: nums1[i+1];
            int left2 = (j==-1)? INT_MIN: nums2[j];
            int right2 = (j==m-1)? INT_MAX: nums2[j+1];

            if(left1 <= right2 && left2 <= right1){
                break;
            }

            else if(left1 > right2) {
                r = i;
            }

            else {
                l = i+1;
            }
        }

        int i = l + (r-l)/2;
        int j = half-(i+1)-1;
        

        int left1 = (i==-1)? INT_MIN: nums1[i];
        int right1 = (i==n-1)? INT_MAX: nums1[i+1];
        int left2 = (j==-1)? INT_MIN: nums2[j];
        int right2 = (j==m-1)? INT_MAX: nums2[j+1];

        int left = max(left1, left2);
        int right = min(right1, right2);

        if((m+n)%2 == 0)
            return (double) (left+right)/2;
        else
            return left;

    }
};