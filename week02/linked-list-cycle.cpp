class Solution {
public:
    // TC: O(N)
    // SC: O(1)
    bool hasCycle(ListNode *head) {
        auto slow = head;
        auto fast = head;

        while(fast && fast -> next) {
            fast = fast -> next -> next;
            slow = slow -> next;

            if(fast == slow) return true;
        }

        return false;
    }
};