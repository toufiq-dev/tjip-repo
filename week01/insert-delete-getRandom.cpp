class RandomizedSet {
public:
    // TC: O(1)
    // SC: O(N)
    vector<int> arr;
    unordered_map<int, int> idxMap;

    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(idxMap.count(val)) 
            return false;

        idxMap[val] = arr.size();
        arr.push_back(val);
        
        return true;
    }
    
    bool remove(int val) {
        if(idxMap.count(val) == 0)
            return false;
        
        swap(arr[idxMap[val]], arr[arr.size() - 1]);
        arr.pop_back();

        // remove from map
        idxMap[arr[idxMap[val]]] = idxMap[val];
        idxMap.erase(val);  
        
        return true;
    }
    
    int getRandom() {
        int randomIdx = rand() % arr.size();

        return arr[randomIdx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */