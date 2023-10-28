class Solution {
public:
    // TC: O(N)
    // SC: O(N)
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> nodeMap;

        auto current = head;
        while (current) {
            nodeMap[current] = new Node(current -> val);
            current = current -> next;
        }
        
        current = head;
        while (current) {
            auto copyNode = nodeMap[current];
            copyNode -> next = nodeMap[current -> next];
            copyNode -> random = nodeMap[current -> random];
            current = current -> next;
        }

        return nodeMap[head];
    }
};