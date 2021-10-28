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
    ListNode* oddEvenList(ListNode* head) {

        if (!head) {
            return NULL;
        }

        ListNode *odd = head;
        ListNode *second = head->next;
        ListNode *secondHead = second;
        while (second && second->next) {
            odd->next = second->next;
            odd = odd->next;
            second->next = odd->next;
            second = second->next;
        }
        odd->next = secondHead;
        return head;
    }
};
