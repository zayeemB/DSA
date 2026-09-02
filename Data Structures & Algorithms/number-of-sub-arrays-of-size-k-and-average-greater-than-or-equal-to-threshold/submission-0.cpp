class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int currSum = 0, count = 0;
        for(int i = 0; i < n; i++){
            if(i < k){
                currSum += arr[i];
                if(i == k-1 && (currSum)/k >= threshold)
                    count++;
            }
            else{
                currSum -= arr[i-k];
                currSum += arr[i];
                if((currSum)/k >= threshold)
                    count++;
            }
        }
        return count;
    }
};