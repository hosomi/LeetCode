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
    ListNode* swapPairs(ListNode* head) { 
 
        ListNode ln(0);
        ln.next = head;
        head = &ln;
 
        while (head && head->next && head->next->next) {
            auto lnp1 = head->next;
            auto lnp2 = lnp1->next;
            lnp1->next = lnp2->next;
            lnp2->next = lnp1;
            head->next = lnp2;
            head = lnp1;
        }
        return ln.next;
    }
};
