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
        // Initialize two pointers
        ListNode* slow = head;
        ListNode* fast = head;

        // Traverse the list with the two pointers
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;              // Move slow pointer by 1 step
            fast = fast->next->next;        // Move fast pointer by 2 steps
            
            // If the slow and fast pointers meet, there's a cycle
            if (slow == fast) {
                return true;
            }
        }

        // If fast pointer reaches the end, there's no cycle
        return false;
    }
};
