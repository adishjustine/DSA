class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        // Handle empty list
        if (!head) {
            return nullptr;
        }
      
        // Initialize pointers for odd and even nodes
        ListNode* oddCurrent = head;                    // Current odd position node
        ListNode* evenCurrent = head->next;             // Current even position node
        ListNode* evenHead = evenCurrent;               // Save the head of even list for later connection
      
        // Rearrange nodes by alternating odd and even positions
        // Continue while there are even nodes and nodes after them
        while (evenCurrent && evenCurrent->next) {
            // Connect current odd node to the next odd node (skip even node)
            oddCurrent->next = evenCurrent->next;
            oddCurrent = oddCurrent->next;
          
            // Connect current even node to the next even node (skip odd node)
            evenCurrent->next = oddCurrent->next;
            evenCurrent = evenCurrent->next;
        }
      
        // Connect the end of odd list to the beginning of even list
        oddCurrent->next = evenHead;
      
        return head;
    }
};