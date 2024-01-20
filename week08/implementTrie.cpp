class Trie {
public:
    class Node {
    public: 
        int cnt;
        bool isEnd;
        unordered_map<int, Node*> next;

        Node() {
            cnt = 0;
            isEnd = false;
        }
    };

    Node* root;

    Trie() {
        root = new Node();
    }
    
    // TC: O(M)
    // TC: O(M)
    void insert(string word) {
        auto curr = root;
        for(char &c : word) {
            int rnk = c - 'a';
            if(curr -> next[rnk] == nullptr) {
                curr -> next[rnk] = new Node();
            }

            curr = curr -> next[rnk];
            curr -> cnt++;
        }
        curr -> isEnd = true;
    }
    
    // TC: O(M)
    // SC: O(1)
    bool search(string word, bool isPrefixSearch = false) {
        auto curr = root;
        for(char &c : word) {
            int rnk = c - 'a';
            if(curr -> next[rnk] == nullptr) {
                return false;
            }

            curr = curr -> next[rnk];
        }
        return isPrefixSearch || curr && curr -> isEnd;
    }
    
    // TC: O(M)
    // SC: O(1)
    bool startsWith(string prefix) {
        return search(prefix, true);
    }
};
