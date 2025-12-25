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
    ListNode* deleteMiddle(ListNode* head) {
        // Create a dummy node pointing to head to handle edge cases
        // (e.g., when the list has only one or two nodes)
        ListNode* dummyNode = new ListNode(0, head);
      
        // Initialize two pointers for the two-pointer technique
        // slowPtr will eventually point to the node before the middle node
        ListNode* slowPtr = dummyNode;
        // fastPtr moves twice as fast as slowPtr
        ListNode* fastPtr = head;
      
        // Move fastPtr two steps and slowPtr one step at a time
        // When fastPtr reaches the end, slowPtr will be just before the middle
        while (fastPtr != nullptr && fastPtr->next != nullptr) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
      
        // Delete the middle node by skipping it
        // slowPtr->next is the middle node to be deleted
        slowPtr->next = slowPtr->next->next;
      
        // Return the head of the modified list
        // dummyNode->next handles the case where the original head was deleted
        return dummyNode->next;
    }
};