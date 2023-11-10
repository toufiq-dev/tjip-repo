class Solution {
public:
    // TC: O(1)
    // SC: O(1)
    void deleteNode(ListNode* node) {
        auto remove_node = node -> next;
        node -> val = node -> next -> val;
        node -> next = node -> next -> next;
        delete(remove_node);
    }
};