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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL){     // Edge Case: Either Lisked List is empty => then NO intersection possible!
            return NULL;
        }

        ListNode* first = headA;
        ListNode* second = headB;

        while(first != second){
            if(first == NULL){   // If first list's pointer reached the last
                first = headB;
            }else{
                first = first -> next;  // Normal Iteration Process
            }

            if(second == NULL){    // If second list's pointer reached the last
                second = headA;
            }else{
                second = second -> next;  // Normal Iteration Process
            }
        }

        return first;
    }
};