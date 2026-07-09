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
    void reorderList(ListNode* head) {
        ListNode *first = head, *second = head;

        while(second != nullptr && second->next != nullptr){
            first = first->next;
            second = second->next->next;
        }

        ListNode *end1 = first;
        second = first; first = nullptr;

        while(second != nullptr){
            ListNode *next_node = second->next;

            second->next = first;
            first = second;
            second = next_node;
        }

        ListNode *begin1 = head, *begin2 = first;
        while(begin1->next != end1 && begin2->next != nullptr){
            ListNode *next_node1 = begin1->next;
            ListNode *next_node2 = begin2->next;

            begin1->next = begin2;
            begin2->next = next_node1;

            begin1 = next_node1;
            begin2 = next_node2;
        }
        if(begin2->next != nullptr)
            begin1->next = begin2;
    }
};
