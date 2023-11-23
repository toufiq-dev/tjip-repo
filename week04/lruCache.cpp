class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;    
    }
    
    int get(int key) {
        if(!k_val.count(key)) return -1;
        updateLRU(key);
        return k_val[key];
    }
    
    void put(int key, int value) {
        if (!k_val.count(key) and lru.size() == cap) 
            evict();

        updateLRU(key);
        k_val[key] = value;        
    }

private: 
    int cap;
    list<int> lru;
    unordered_map<int, list<int>::iterator> k_loc;
    unordered_map<int, int> k_val;

    void updateLRU(int key) {
        if(k_val.count(key)) 
            lru.erase(k_loc[key]);

        lru.push_front(key);
        k_loc[key] = lru.begin();
    }

    void evict() {
        k_val.erase(lru.back());
        k_loc.erase(lru.back());
        lru.pop_back();
    }
};
