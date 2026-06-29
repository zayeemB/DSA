class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if(arr.size() == 1) return 1;
        
        int max_subarr = 1;
        int curr_subarr = 0;

        bool flag_e = true;
        bool flag = false;

        for(int i = 0; i < arr.size()-1; i++){
            if(arr[i] == arr[i+1]){
                flag_e = true;
                continue;
            }

            if(flag_e){
                flag_e = false;
                curr_subarr = 2;
            }
            else{
                if(!flag == arr[i] > arr[i+1]) curr_subarr++;
                else curr_subarr = 2;
            }

            flag = arr[i] > arr[i+1];
            max_subarr = max(max_subarr, curr_subarr);
        }

        return max_subarr;
    }
};