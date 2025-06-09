class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Create a dummy node to simplify edge cases (like adding first node)
        ListNode* dummy = new ListNode(0);

        // Pointer to build the result list starting from dummy
        ListNode* curr = dummy;

        // Initialize carry to 0
        int carry = 0;

        // Continue looping until all nodes and carry are processed
        while (l1 || l2 || carry) {
            int sum = carry;  // Start with carry from previous addition

            // If l1 is not null, add its value and move to next node
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }

            // If l2 is not null, add its value and move to next node
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            // Update carry for next iteration
            carry = sum / 10;

            // Create a new node with the digit part (unit's place) of the sum
            curr->next = new ListNode(sum % 10);

            // Move the pointer ahead in the result list
            curr = curr->next;
        }

        // Return the next of dummy node, which is the actual result list
        return dummy->next;
    }
};
