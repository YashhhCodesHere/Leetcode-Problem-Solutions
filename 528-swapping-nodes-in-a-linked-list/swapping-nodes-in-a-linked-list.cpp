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
 #include <bits/stdc++.h>
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if(head == nullptr || head -> next == nullptr){
            return head;
        }
        
        ListNode* temp = head;
        int size = 0;
        while(temp != nullptr){
            temp = temp -> next;
            size++;
        }

        ListNode* fromStart = head;
        for(int i = 1; i < k; i++){
            fromStart = fromStart -> next;
        }

        ListNode* fromEnd = head;
        for(int i = 1; i < size - k + 1; i++){
            fromEnd = fromEnd -> next;
        }

        swap(fromStart -> val, fromEnd -> val);

        return head;
    }
};