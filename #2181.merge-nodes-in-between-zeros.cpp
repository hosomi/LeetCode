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
    ListNode* mergeNodes(ListNode* head) {

        ListNode *it = head->next;
        ListNode *itHead = head;     
        while (it->next != NULL) {
            if (it->val == 0) {
                itHead = itHead->next = it;
            } else {
                itHead->val += it->val;
            }
            it = it->next;
        }
        itHead -> next = NULL;
        return head;
    }
};
