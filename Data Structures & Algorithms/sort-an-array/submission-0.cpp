class Solution {
void mergeSort(vector<int> &nums, vector<int> &temp, int start, int end){
    if(start == end)
        return;
    
    int mid = start + (end-start)/2;

    mergeSort(nums, temp, start, mid);
    mergeSort(nums, temp, mid + 1, end);

    int lidx = start, ridx = mid+1;
    int idx = 0;
    while(lidx <= mid && ridx <= end){
        if(nums[lidx] < nums[ridx]){
            temp[idx++] = nums[lidx++];
        }
        else{
            temp[idx++] = nums[ridx++];
        }
    }

    while(lidx <= mid){
        temp[idx++] = nums[lidx++];
    }

    while(ridx <= end){
        temp[idx++] = nums[ridx++];
    }

    for(int i = end; i >= start; i--){
        nums[i] = temp[--idx];
    }
    return;
}

public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> temp(nums.size());
        mergeSort(nums, temp, 0, nums.size()-1);
        return nums;
    }
};