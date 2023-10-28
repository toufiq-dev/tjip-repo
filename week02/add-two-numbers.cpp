class Solution {
public:
    // TC: O(N)
    // SC: O(N)
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0, carry = 0;
        ListNode* dummy = new ListNode(); 
        ListNode* current = dummy;

        while (l1 || l2 || carry) {
        int x = l1 ? l1 -> val : 0;
        int y = l2 ? l2 -> val : 0;
                
        sum = x + y + carry;
        carry = sum / 10; 
        sum %= 10;

        current -> next = new ListNode(sum);
        current = current -> next;

        if (l1) l1 = l1 -> next;
        if (l2) l2 = l2 -> next;
        }

        return dummy -> next; 
    }
};