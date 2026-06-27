class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();

        struct Project{
            int capital;
            int profit;

            Project(int c, int p){
                capital = c;
                profit = p;
            }
        };

        auto comp_capital = [](Project a, Project b){
            return a.capital < b.capital;
        };

        auto comp_profit = [](Project a, Project b){
            return a.profit < b.profit;
        };

        priority_queue<Project, vector<Project>, decltype(comp_profit)> pq_profit;

        vector<Project> projects;

        for(int i = 0; i < n; i++){
            projects.push_back(Project(capital[i], profits[i]));
        }

        sort(projects.begin(), projects.end(), comp_capital);

        int cap = w;
        int project_count = 0;

        int idx = 0;

        while((idx < n || !pq_profit.empty()) && project_count < k){
            while(idx < n && projects[idx].capital <= cap){
                pq_profit.push(projects[idx]);
                idx++;
            }
            
            if(!pq_profit.empty()){
                Project most_profitable = pq_profit.top(); pq_profit.pop();

                cap += most_profitable.profit;
                project_count++;
            }
            else break;
        }
        
        return cap;
    }
};