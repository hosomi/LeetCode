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
    void reorderList(ListNode* head) {

        vector<ListNode*> v;
        ListNode* ln = head;
        int i = 0;
        int j = 0;
        while (ln) {
            v.push_back(ln);
            j++;
            ln = ln->next;
        }
        j--;

        while (i < j) {
            v[i]->next = v[j];
            i++;
            if (i<j) {
                v[j]->next = v[i];
            }
            j--;
        }
        v[i]->next = NULL;
    }
};
