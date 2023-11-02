class Solution {
public:
    // TC: O(N) where N = |list1| / |list2|
    // SC: O(1)
    void addAtTail(ListNode*& dHead, int val) {
        auto newNode = new ListNode(val);
        dHead -> next = newNode;
        dHead = newNode;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        auto dHead = new ListNode();
        auto cHead = dHead;

        while(list1 && list2) {
            if(list1 -> val < list2 -> val) {
                addAtTail(dHead, list1 -> val);
                list1 = list1 -> next;
            } else {
                addAtTail(dHead, list2 -> val);
                list2 = list2 -> next;
            }
        }

        if(list1) dHead -> next  = list1;
        if(list2) dHead -> next = list2;

        return cHead -> next;
    }
};