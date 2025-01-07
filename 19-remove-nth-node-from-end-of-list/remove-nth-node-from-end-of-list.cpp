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
        // Create a dummy node to handle edge cases like removing the head
        ListNode* dummy = new ListNode(0, head);
        ListNode* first = dummy;
        ListNode* second = dummy;

        // Move the `first` pointer `n + 1` steps ahead
        for (int i = 0; i <= n; i++) {
            first = first->next;
        }

        // Move both pointers until `first` reaches the end
        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }

        // `second` is now just before the node to be removed
        ListNode* toDelete = second->next;
        second->next = second->next->next;
        delete toDelete;

        // Return the new head, skipping the dummy node
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
