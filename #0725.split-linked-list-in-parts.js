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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        ListNode* cur = head;
        int n = 0;
        while (cur) {
            n++;
            cur = cur->next;
        }
        
        int width = n / k;
        int rem = n % k;
        vector<ListNode*> result(k, NULL);
        cur = head;
        for (int i = 0; i < k; i++) {
            ListNode* head = cur;
            ListNode* prev = cur;
            for (int j = 0; j < width + (i < rem ? 1 : 0) - 1; j++) {
                if (prev) {
                    prev = prev->next;
                }
            }

            if (prev) {
                cur = prev->next;
                prev->next = NULL;
            }
            result[i] = head;
        }
        return result;
    }
};
