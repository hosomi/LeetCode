/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        ListNode* result = head;
        unordered_map<ListNode*,bool> um;
        while (result != nullptr) {
            if (um.count(result) != 0) {
                break;
            }
            um[result] = true;
            result = result->next;
        }
        return result;
    }
};
