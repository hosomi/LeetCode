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
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* ln = head;
        int index = 0;
        for (; index < k && ln; ++index) {
            ln = ln->next;
        }

        if (index < k) {
            return head;
        }

        ln = reverseKGroup(ln, k);
        ListNode* lnwork;
        for (int i = 0; i < k; ++i) {
            lnwork = head->next;
            head->next = ln;
            ln = head;
            head = lnwork;
        }

        return ln;
    }
};
