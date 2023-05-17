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
    int pairSum(ListNode* head) {
        
        vector<int>v;
        while (head) {
            v.push_back(head->val);
            head = head->next;
        }
        
        int left = 0;
        int right = v.size() - 1;
        int max = INT_MIN;
        while (left < right) {
            max = std::max(max, v[left] + v[right]);
            left++;
            right--;
        }
        return max;
    }
};
