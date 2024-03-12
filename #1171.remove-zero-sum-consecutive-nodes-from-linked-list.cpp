/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullln) {}
 *     ListNode(int x) : val(x), next(nullln) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {

        unordered_map<int,ListNode*> u;
        ListNode* ln;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ln = dummy;
        int sum = 0;
        while (ln) {
            sum += ln->val;
            u[sum] = ln;
            ln = ln->next;
        }

        ListNode* lntemp;
        sum = 0;
        ln = dummy;
        while (ln) {
            sum += ln->val;
            lntemp = ln->next;
            while (u[sum] != NULL && lntemp != u[sum]->next) {
                lntemp = lntemp->next;
            }
            ln->next = lntemp;
            ln = lntemp;
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};
