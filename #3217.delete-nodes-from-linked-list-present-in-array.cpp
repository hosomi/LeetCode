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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {

        unordered_set<int> s(nums.begin(), nums.end());
        ListNode* node = new ListNode();
        node->next = head;
        ListNode* p = node;
        while (p) {
            while (p->next && s.count(p->next->val)) {
                p->next = p->next->next;
            }
            p = p->next;
        }        
        return node->next;
    }
};
