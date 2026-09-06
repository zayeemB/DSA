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
    int pairSum(ListNode* head) {
        ListNode *first = head, *second = head;

        while(second != nullptr && second->next != nullptr){
            first = first->next;
            second = second->next->next;
        }

        second = first;
        first = nullptr;

        while(second != nullptr){
            ListNode *next = second->next;
            second->next = first;
            first = second;
            second = next;
        }

        second = first;
        first = head;

        int maxVal = 0;

        while(first != nullptr && second != nullptr){
            maxVal = max(maxVal, first->val + second->val);

            first = first->next;
            second = second->next;
        }

        return maxVal;
    }
};