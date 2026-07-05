class MyStack {
public:
    queue<int> q1;
    queue<int> q2;

    MyStack() {
        return;
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        while(q1.size() > 1){
            q2.push(q1.front()); q1.pop();
        }

        if(!q1.empty()){
            int r = q1.front(); q1.pop();
            return r;
        }

        while(q2.size() > 1){
            q1.push(q2.front()); q2.pop();
        }

        int r = q2.front(); q2.pop();
        return r;
    }
    
    int top() {
        while(q1.size() > 1){
            q2.push(q1.front()); q1.pop();
        }

        if(!q1.empty()){
            int r = q1.front();
            return r;
        }

        while(q2.size() > 1){
            q1.push(q2.front()); q2.pop();
        }

        int r = q2.front(); q2.pop();
        q1.push(r);
        return r;
    }
    
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */