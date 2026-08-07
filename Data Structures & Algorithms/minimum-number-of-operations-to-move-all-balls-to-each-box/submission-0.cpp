class Solution {
public:
    vector<int> minOperations(string boxes) {
        // vector<int> res(boxes.size(),0);
        // for(int i = 0; i < boxes.size(); i++){
        //     int count = 0;
        //     for(int j = 0; j < boxes.size(); j++){
        //         if(i == j) continue;
        //         if(boxes[j] == '1') count += abs(i-j);
        //     }
        //     res[i] = count;
        // }
        // return res;

        vector<int> prefix_count(boxes.size()+1,0);
        vector<int> suffix_count(boxes.size()+1,0);

        for(int i = 1; i < prefix_count.size(); i++){
            if(boxes[i-1] == '1') prefix_count[i] = prefix_count[i-1]+1;
            else prefix_count[i] = prefix_count[i-1];
        }

        for(int i = suffix_count.size()-2; i >= 0; i--){
            if(boxes[i] == '1') suffix_count[i] = suffix_count[i+1]+1;
            else suffix_count[i] = suffix_count[i+1];
        }

        vector<int> prefix_steps(boxes.size(), 0);
        for(int i = 1; i < prefix_steps.size(); i++) 
            prefix_steps[i] = prefix_count[i] + prefix_steps[i-1];

        vector<int> suffix_steps(boxes.size(), 0);
        for(int i = boxes.size()-2; i >= 0; i--) 
            suffix_steps[i] = suffix_count[i+1] + suffix_steps[i+1];

        vector<int> res(boxes.size());
        for(int i = 0; i < boxes.size(); i++){
            res[i] = prefix_steps[i] + suffix_steps[i];
        }
        return res;
    }
};