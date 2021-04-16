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

        ListNode result = ListNode(0);
        ListNode *work = &result;
        int index;
        while (head) {
            index = 0;
            while (head->next && head->next->val == head->val) {
                head = head->next;
                index++;
            }
            if (index == 0) {
                work = work->next = head;
            } else {
                work->next = nullptr;
            }
          head = head->next;
        }
        return result.next;
    }
};
