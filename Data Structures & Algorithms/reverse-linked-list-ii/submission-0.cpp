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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == nullptr || head->next == nullptr) return head;

        ListNode *dummy_head = new ListNode(0, head);
        ListNode *node = dummy_head;
        
        ListNode *l = head, *r = head, *l_prev = nullptr;

        int idx = 0;

        while(node != nullptr){
            if(idx+1 == left)
                l_prev = node;

            if(idx == left)
                l = node;
            
            if(idx == right){
                r = node;
            }

            idx++;
            node = node->next;
        }

        l_prev->next = r;
        ListNode *end = r->next;

        ListNode *first = r->next, *second = l;

        while(second != end){
            ListNode *next_node = second->next;

            second->next = first;
            first = second;
            second = next_node;
        }

        return dummy_head->next;
    }
};