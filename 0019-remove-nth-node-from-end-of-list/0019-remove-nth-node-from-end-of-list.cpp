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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // if(head==NULL) return head;
        ListNode *dummy= new ListNode(0);  //create a dummy node
        dummy->next=head;

        ListNode* ptr1=dummy;             //point both to dummy
        ListNode* ptr2=dummy;

        for(int i=0;i<n;i++){
            ptr2=ptr2->next;
        }

        while(ptr2->next != NULL){
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        ptr1->next=ptr1->next->next;

        return dummy->next;

    }
};