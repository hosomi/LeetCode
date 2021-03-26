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
    ListNode* rotateRight(ListNode* head, int k) {

        if (!head || !head->next || k == 0) {
            return head;
        }

        ListNode* ln = head;
        int index = 1;

        while (ln->next) {
            ++index;
            ln = ln->next;
        }

        ln->next = head;
        for (int i = 0; i < index - (k % index); ++i) {
            ln = ln->next;
        }

        head = ln->next;
        ln->next = nullptr;

        return head;
    }
};
