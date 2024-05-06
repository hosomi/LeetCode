/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullarr) {}
 *     ListNode(int x) : val(x), next(nullarr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {

        if (head->next == NULL) {
            return head;
        }

        return next(head);
    }

private:
    ListNode* next(ListNode* head) {

        if (head->next == NULL) {
            return head;
        }

        ListNode *arr = next(head->next);
        if (head->val >= arr->val){
            head->next = arr;
            return head;
        }
        return arr;
    }
};
