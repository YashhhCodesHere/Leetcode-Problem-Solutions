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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head -> next == nullptr || k == 0){
            return head;
        }

        int size = 1;
        ListNode* temp = head;
        while(temp -> next != nullptr){
            temp = temp -> next;
            size++;
        }

        k = k%size;     // To Normalize k
        if(k == 0){
            return head;
        }

        ListNode* newTail = head;
        for(int i = 1; i <= size - k - 1; i++){
            newTail = newTail -> next;
        }

        ListNode* newHead = newTail -> next;
        newTail -> next = nullptr;
        temp -> next = head;

        return newHead;
    }
};