/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> visited_node;
        ListNode *current_node=head;
         while (current_node != nullptr) {
            if (visited_node.find(current_node) != visited_node.end()) {
                return true;
            }
            visited_node.insert(current_node);
            current_node = current_node->next;
        }
        return false;
    }
};