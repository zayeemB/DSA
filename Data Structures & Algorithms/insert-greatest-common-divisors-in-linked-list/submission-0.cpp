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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next == nullptr) return head;

        ListNode *curr = head;
        ListNode *next = head->next;

        while(next != nullptr){
            ListNode* new_node = new ListNode(gcd(curr->val, next->val));
            new_node->next = next;
            curr->next = new_node;

            curr = next;
            next = next->next;
        }

        return head;
    }
};