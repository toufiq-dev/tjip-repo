class Solution {
public:
    // TC: O(N)
    // SC: O(1)
    ListNode* reverseList(ListNode* head) {
        auto curr = head;
        ListNode* prev = nullptr;

        while(curr) {
            auto nxt = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nxt;
        }

        return prev;
    }
};