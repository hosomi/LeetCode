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

        if (!head || !head->next) {
            return head;
        }

        ListNode* p = head;
        while (p->next) {
            int gcd = __gcd(p->val, p->next->val);
            ListNode* mid = new ListNode(gcd, p->next);
            p->next = mid;
            p = mid->next;
        }
        return head;
    }
};
