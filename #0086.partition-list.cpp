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
    ListNode* partition(ListNode* head, int x) {

        ListNode* result = new ListNode(-1);
        result->next = head;
        ListNode* work = result;
        ListNode* cursor = head;
        while (work->next && work->next->val < x) {
             work = work->next;
        }

        cursor = work;
        ListNode* next;
        while (cursor->next) {
            if (cursor->next->val < x){
                next = cursor->next;
                cursor->next = next->next;
                next->next = work->next;
                work->next = next;
                work = next;
            } else {
                 cursor = cursor->next;
            }
        }
        return result->next;
    }
};
