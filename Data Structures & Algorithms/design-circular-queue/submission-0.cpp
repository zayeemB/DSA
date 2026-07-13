class MyCircularQueue {
    struct Node{
        int val;
        Node *next;

        Node(int val){
            this->val = val;
            next = nullptr;
        }
    };

public:
    Node *tail;
    int size;
    int capacity;
    MyCircularQueue(int k) {
        capacity = k;
        size = 0;
        tail = nullptr;
        return;
    }
    
    bool enQueue(int value) {
        if(size == capacity){
            return false;
        }

        if(size == 0){
            tail = new Node(value);
            tail->next = tail;
            size++;
            return true;
        }

        Node *new_node = new Node(value);

        new_node->next = tail->next;
        tail->next = new_node;
        tail = tail->next;
        size++;

        return true;
    }
    
    bool deQueue() {
        if(size == 0){
            return false;
        }

        if(size == 1){
            delete(tail);
            tail = nullptr;
            size--;
            return true;
        }

        Node *temp = tail->next;
        tail->next = temp->next;
        size--;

        delete(temp);
        return true;
    }
    
    int Front() {
        if(size == 0)
            return -1;
        
        if(size == 1)
            return tail->val;
        else
            return tail->next->val;
    }
    
    int Rear() {
        if(size == 0)
            return -1;

        return tail->val;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */