/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* curr=dummy;

        // Traverse the list while current node and its next exist
        while (curr != nullptr && curr->next != nullptr) {
            // If the next node's value is equal to the target, skip it
            if (curr->next->val == val) {
                curr->next = curr->next->next;  // Remove the node
            } else {
                curr = curr->next;  // Move to next node
            }
        }

        // Return the new head (skipping dummy)
        return dummy->next;
    }
};