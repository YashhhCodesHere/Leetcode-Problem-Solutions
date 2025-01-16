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
    ListNode* splitAtMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while(fast != nullptr && fast -> next != nullptr){
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        if(prev != nullptr){
            prev -> next = nullptr;
        }

        return slow;
    }

    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* forw = nullptr;

        while(curr != nullptr){
            forw = curr -> next;

            curr -> next = prev;
            prev = curr;
            curr = forw;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        ListNode* rightHead = splitAtMid(head);
        ListNode* rightHeadReversed = reverse(rightHead);

        ListNode* left = head;
        ListNode* right = rightHeadReversed;
        ListNode* tail = right;

        while(left != nullptr && right != nullptr){
            ListNode* leftNext = left -> next;
            ListNode* rightNext = right -> next;

            left -> next = right;
            right -> next = leftNext;

            tail = right;

            left = leftNext;
            right = rightNext;
        }

        if(right != nullptr){
            tail -> next = right;
        }
    }
};