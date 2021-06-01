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
    bool hasCycle(ListNode *head) {

        auto node1 = head;
        auto node2 = head;
        while (node1) {
            if (!node1->next) {
                return false;
            }
    
            node1 = node1->next->next;
            node2 = node2->next;
            if (node1 == node2) {
                return true;
            }
        }
        return false;
    }
};
