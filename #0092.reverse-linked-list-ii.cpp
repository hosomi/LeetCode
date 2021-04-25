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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        ListNode *result = new ListNode(-1);
        result->next = head;
        ListNode *pre = result;
        ListNode *cur = head;
        int i = 1;
        for(; i < left; ++i){
            pre = pre->next;
            cur = cur->next;
        }

        ListNode *precur = pre;
        ListNode *cursave = cur;
        ListNode* curnext;
        for(; i <= right; ++i){
            curnext = cur->next;
            cur->next = pre;
            pre = cur;
            cur = curnext;
        }

        precur->next = pre;
        cursave->next = cur;
        return result->next;
    }
};
