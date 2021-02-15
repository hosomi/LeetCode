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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        vector<ListNode *> v;
        ListNode *ln = head;
        while (ln) {
            v.push_back(ln);
            ln = ln->next;
        }

        if (n == v.size()) {
            return head->next;
        }
        ListNode* v_remove = v[v.size()-n];
        ListNode* v_parent = v[v.size() - n - 1];
        v_parent->next = v_remove->next;
        delete v_remove;
        return head;
    }
};
