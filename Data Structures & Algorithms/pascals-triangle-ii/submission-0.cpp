class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0) return {1};
        if(rowIndex == 1) return {1,1};

        vector<int> curr = {1,1};
        for(int i = 2; i <= rowIndex; i++){
            vector<int> temp(1,1);
            for(int i = 0; i < curr.size()-1; i++)
                temp.push_back(curr[i]+curr[i+1]);
            temp.push_back(1);
            curr = temp;
        }
        return curr;
    }
};