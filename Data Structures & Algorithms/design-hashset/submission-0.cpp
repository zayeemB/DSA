class MyHashSet {
public:
    vector<bool> buckets;
    MyHashSet() {
        buckets.resize(8, false);
        return;
    }
    
    void add(int key) {
        if(key >= buckets.size()){
            size_t new_size = std::max((size_t)key + 1, buckets.size() * 2);
            buckets.resize(new_size);
        }
        buckets[key] = true;
    }
    
    void remove(int key) {
        if(key < buckets.size())
            buckets[key] = false;
    }
    
    bool contains(int key) {
        if(key < buckets.size() && buckets[key]) return true;
        return false; 
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */