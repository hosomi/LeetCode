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
    ListNode* deleteDuplicates(ListNode* head) {

        auto ln = head;
        while (ln) {
            if (ln->next && ln->next->val == ln->val) {
                ln->next = ln->next->next;
            } else {
                ln = ln->next;
            }
        }
        return head;
    }
};
