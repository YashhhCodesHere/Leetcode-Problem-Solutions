class Solution {
public:
    // Function to split the linked list into two halves
    ListNode* splitAtMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        // Find the middle using slow and fast pointers
        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Disconnect the first half from the second
        if (prev != nullptr) {
            prev->next = nullptr;
        }

        return slow; // Return the head of the second half
    }

    // Merge two sorted linked lists
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* dummy = new ListNode(); // Dynamically allocate the dummy node
        ListNode* tail = dummy;

        // Merge the two lists
        while (left != nullptr && right != nullptr) {
            if (left->val <= right->val) {
                tail->next = left;
                left = left->next;
            } else {
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }

        // Attach the remaining nodes from either list
        if (left != nullptr) {
            tail->next = left;
        }
        if (right != nullptr) {
            tail->next = right;
        }

        ListNode* result = dummy->next; // Store the head of the merged list
        delete dummy;                  // Free the dummy node to avoid memory leaks
        return result;                 // Return the merged list
    }

    // Main function to sort the linked list
    ListNode* sortList(ListNode* head) {
        // Base case: if the list is empty or has only one element, it's already sorted
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Split the list into two halves
        ListNode* rightHead = splitAtMid(head);

        // Recursively sort the two halves
        ListNode* left = sortList(head);
        ListNode* right = sortList(rightHead);

        // Merge the sorted halves
        return merge(left, right);
    }
};