class RandomizedSet {
public:
    vector<int> arr;
    unordered_map<int, int> map;

    RandomizedSet() {
    }
    
    bool insert(int val) {

        if (map.find(val) != map.end()) return false;
        
        arr.push_back(val); 
        map[val] = arr.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (map.find(val) == map.end()) return false;
        
        int idx = map[val];
        int lastVal = arr.back();
        
        arr[idx] = lastVal;
        map[lastVal] = idx;
        
        arr.pop_back();
        map.erase(val);
        return true;
    }
    
    int getRandom() {
        return arr[rand() % arr.size()];
    }
};