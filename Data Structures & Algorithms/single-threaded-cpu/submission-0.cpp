class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        struct Task {
            int enqueueTime;
            int processingTime;
            int index;

            
        };

        int n = tasks.size();

        vector<Task> sorted_tasks(n);
        for(int i = 0; i < n; i++) {
            sorted_tasks[i] = {tasks[i][0], tasks[i][1], i};
        }

        sort(sorted_tasks.begin(), sorted_tasks.end(), [](const Task& a, const Task& b){
            return a.enqueueTime < b.enqueueTime;
        });

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> ready_tasks;  

        long long time = 0;
        int i = 0;

        vector<int> order;

        while(i < n || !ready_tasks.empty()){
            if(ready_tasks.empty())
                time = max(time, (long long)sorted_tasks[i].enqueueTime);

            while(i < n && sorted_tasks[i].enqueueTime <= time){
                Task task =  sorted_tasks[i];
                ready_tasks.push({task.processingTime, task.index});
                i++;
            }

            order.push_back(ready_tasks.top().second);

            time += ready_tasks.top().first;
            ready_tasks.pop();
        }

        return order;
    }
};