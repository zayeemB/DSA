class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;

    MyQueue() {
        return;
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        if(!st2.empty()){
            int e = st2.top(); st2.pop();
            return e;
        }
        else{
            while(!st1.empty()){
                st2.push(st1.top()); st1.pop();
            }
            int e = st2.top(); st2.pop();
            return e;
        }
        
    }
    
    int peek() {
        if(!st2.empty()){
            int e = st2.top();
            return e;
        }
        else{
            while(!st1.empty()){
                st2.push(st1.top()); st1.pop();
            }
            int e = st2.top();
            return e;
        }
    }
    
    bool empty() {
        return st1.empty() && st2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */