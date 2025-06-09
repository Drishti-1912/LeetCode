class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // Base case: if the list is empty, return null
        if (head == nullptr) return nullptr;

        // Recursively call on the rest of the list
        head->next = removeElements(head->next, val);

        // If current node matches the target value, skip it
        if (head->val == val)
            return head->next;
        else
            return head;
    }
};
