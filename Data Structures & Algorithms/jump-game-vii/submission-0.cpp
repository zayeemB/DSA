class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if(s.back() == '1') return false;
        if(maxJump >= s.size()-1) return true;

        queue<int> q;     
        q.push(0);

        int farthest = 0;
        int n = s.size();

        while(!q.empty()){  
            int curr = q.front(); q.pop();
            int start = max(curr + minJump, farthest+1);
            int end = min(n-1, curr + maxJump);
            for(int i = start; i <= end; i++){
                if(s[i] == '0'){
                    if(i == n-1) return true;
                    q.push(i);
                }
            }
            farthest = max(farthest, end);
        }

        return false;
    }
};