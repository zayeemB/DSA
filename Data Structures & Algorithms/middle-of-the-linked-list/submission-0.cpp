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
    ListNode* middleNode(ListNode* head) {
        ListNode *first = head, *second = head;

        int nodes = 0;
        while(head != nullptr){
            nodes++;
            head = head->next;
        }

        while(second->next != nullptr && second->next->next != nullptr){
            first = first->next;
            second = second->next->next;
        }

        return nodes%2 == 0? first->next: first;
    }
};