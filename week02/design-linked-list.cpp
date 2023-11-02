class MyLinkedList {
    // TC: O(N) where N = |ListNode|
    // SC: O(N)
public:
    class ListNode {
    public:
        int val;
        ListNode* next;
        static const int DUMMY_VAL = 0;

        ListNode(int _val = DUMMY_VAL, ListNode* _next = nullptr) : val(_val), next(_next) {}
    };

    int len;
    ListNode* dHead;

    MyLinkedList() : len(0), dHead(new ListNode(ListNode::DUMMY_VAL)) {}
    
    int get(int index) {
        if(index < 0 || index >= len) return -1;
        ListNode* cHead = dHead -> next;
        
        while(index--) cHead = cHead -> next;

        return cHead -> val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(len, val);
    }
    
    void addAtIndex(int index, int val) {
        if(index > len) return;
        ListNode* cHead = dHead;

        while(index--) cHead = cHead -> next;

        ListNode* block = new ListNode(val, cHead -> next);
        cHead -> next = block;
        len++;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= len) return;
        ListNode* cHead = dHead;

        while(index--) cHead = cHead -> next;

        ListNode* delete_candidate = cHead -> next;
        cHead -> next = cHead -> next -> next;
        delete(delete_candidate);
        len--;
    }
};
