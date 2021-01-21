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
    ListNode* insertionSortList(ListNode* head) {

        ListNode *lntemp = new ListNode(-1);
        while (head) {
            ListNode *lnhead = head->next;
            ListNode *p = lntemp;
            while (p->next && p->next-> val <= head->val) {
                p = p->next;
            }

            head->next = p->next;
            p->next = head;

            head = lnhead;
        }
        return lntemp->next;
    }
};
