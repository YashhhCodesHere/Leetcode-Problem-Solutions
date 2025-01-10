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
        head = prev;
        return head;
    }

    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head -> next == nullptr){
            return true;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast -> next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        ListNode* temp = reverse(slow);
        
        ListNode* firstHalfHead = head;
        ListNode* secondHalfHead = temp;

        while(secondHalfHead != nullptr){
            if(firstHalfHead -> val != secondHalfHead -> val){
                return false;
            }
            firstHalfHead = firstHalfHead -> next;
            secondHalfHead = secondHalfHead -> next;
        }

        reverse(temp);  // Optional: Restore the linkedlist as original
        return true;
    }
};