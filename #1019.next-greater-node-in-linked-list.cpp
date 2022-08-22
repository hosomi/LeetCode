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
    vector<int> nextLargerNodes(ListNode* head) {

        ListNode* cur = head;
        vector<int> inputs;
        while (cur) {
            inputs.push_back(cur->val);
            cur = cur->next;
        }
        
        int size = inputs.size();
        stack<int> stk;
        vector<int> result(size, 0);
        for (int i = 0; i < size; i++) {
            while (!stk.empty() && inputs[i] > inputs[stk.top()]) {
                result[stk.top()] = inputs[i];
                stk.pop();
            }
            stk.push(i);
        }
        return result;
    }
};
