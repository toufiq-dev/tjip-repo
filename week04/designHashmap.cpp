class MyHashMap {
private:
    class Node {
    public:
        int key, value;
        Node* next;
        Node (int k, int v, Node* nxt) {
            key = k;
            value = v;
            next = nxt;
        }
    };
    // TC: put, get, remove all have O(n), where, n = no. of keys in hash table
    // and avg case Θ(1)
    // SC: O(1)  
public:
    const static int CAPACITY = 128;
    const static int BASE = 997;
    const static int OFFSET = 1937;
    Node* _lists[CAPACITY] = {};
    MyHashMap() {
        
    }
    
    void put(int key, int value) { 
        remove(key);
        int slotID = calculateHash(key);
        auto node = new Node(key, value, _lists[slotID]);
        _lists[slotID] = node;
    }
    
    int get(int key) {
        int slotID = calculateHash(key);
        auto node = _lists[slotID];
        while(node) {
            if (node -> key == key) 
                return node -> value;
            
            node = node -> next;
        }
        return -1;
    }
    
    void remove(int key) {
        int slotID = calculateHash(key);
        auto node = _lists[slotID];
        
        if (node == nullptr) {
            return;
        }
        
        if (node -> key == key) {
            _lists[slotID] = node -> next;
            delete node;
            return;
        }
        
        while(node && node -> next) {
            if (node -> next -> key == key) {
                auto temp = node -> next;
                node -> next = temp -> next;
                delete temp;
            }
            node = node -> next;
        }
    }
private:
    int calculateHash(int key) {
        return ((key * BASE) + OFFSET) % CAPACITY;
    }
};
