class MyHashMap {
    int numBuckets = 1009;
    vector<list<pair<int,int>>> buckets;

    int hash(int key){
        return key % numBuckets;
    }

public:
    MyHashMap() {
        buckets.assign(numBuckets, {});
    }
    
    void put(int key, int value) {
        int hsh = hash(key);
        list<pair<int,int>> &bucket = buckets[hsh];

        for(auto &p: bucket){
            if(p.first == key){
                p.second = value;
                return;
            }
                
        }

        bucket.push_back({key, value});
    }
    
    int get(int key) {
        int hsh = hash(key);
        list<pair<int,int>> &bucket = buckets[hsh];

        for(auto &p: bucket){
            if(p.first == key)
                return p.second;
        }

        return -1;
    }
    
    void remove(int key) {
        int hsh = hash(key);
        list<pair<int,int>> &bucket = buckets[hsh];
        
        for(auto it = bucket.begin(); it != bucket.end(); it++){
            if(it->first == key){
                bucket.erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */