/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        ListNode *lnheadA = headA;
        ListNode *lnheadB = headB;
        while (lnheadA != lnheadB) {
            lnheadA = lnheadA == NULL ? headB : lnheadA->next;
            lnheadB = lnheadB == NULL ? headA : lnheadB->next;
        }
        return lnheadA;
    }
};
