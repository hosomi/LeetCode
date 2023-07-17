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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        vector<int> v1;
        while (l1 != NULL) {
            v1.push_back(l1->val);
            l1 = l1->next;
        }

        vector<int> v2;
        while (l2 != NULL) {
            v2.push_back(l2->val);
            l2 = l2->next;
        }

        if (v2.size() > v1.size()) {
            swap(v1, v2);
        }

        vector<int> v3;
        int i = 0;
        int s = 0;
        for (i = 0; i < v2.size(); i++) {
            s += v1[v1.size() - i - 1] + v2[v2.size() - i - 1];
            v3.push_back(s % 10);
            s /= 10;
        }

        for (i = v2.size(); i < v1.size(); i++) {
            s += v1[v1.size() - i - 1];
            v3.push_back(s % 10);
            s /= 10;
        }

        if (s > 0) {
            v3.push_back(s);
        }

        ListNode* head = new ListNode;
        ListNode *h = head;
        for (i = v3.size() - 1; i > 0; i--) {
            h->val = v3[i];
            ListNode* temp = new ListNode;
            h->next = temp;
            h = h->next;
        }

        h->val = v3[0];
        return head;
    }
};
