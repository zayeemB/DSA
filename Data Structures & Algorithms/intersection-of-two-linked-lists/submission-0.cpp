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
        ListNode *first = headA, *second = headB;

        while(first != nullptr && second != nullptr){
            first = first->next;
            second = second->next;
        }

        int count = 0;
        
        ListNode *longer = (first == nullptr)? headB: headA;
        ListNode *shorter = (first == nullptr)? headA: headB;

        while(first != nullptr){
            count++;
            first = first->next;
        }
    
        while(second != nullptr){
            count++;
            second = second->next;
        }
      
        for(int i = 0; i < count; i++)
            longer = longer->next;


        while(shorter != longer){
            longer = longer->next;
            shorter = shorter->next;
        }

        return shorter;
    }
};