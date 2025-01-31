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
    ListNode* deleteDuplicates(ListNode* head) {
       if(head==nullptr || head->next==nullptr) return head;

        ListNode *s1 = head;
        ListNode *s2 = s1->next;

        while( s1 != nullptr && s2 != nullptr)
        {
            if (s1->val == s2->val) {
            s1->next = s2->next;
            delete s2; // Free the memory of the duplicate node (optional, depending on your use case)
            s2 = s1->next;
        } else {
            s1 = s1->next;
            s2 = s1->next;
        }
        }
        return head;
    }
};