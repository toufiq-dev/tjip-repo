class Solution {
public:
    // TC: O(N)
    // SC: O(1)
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto slow = new ListNode(0, head);
        auto cslow = slow;
        auto fast = slow;

        while(n--) fast = fast -> next;

        while(fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next;
        }

        auto remove_node = slow -> next;
        slow -> next = slow -> next -> next;
        delete(remove_node);

        return cslow -> next;
    }
};