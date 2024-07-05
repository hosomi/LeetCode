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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        int index = 2;
        int prev = head->val;
        vector<int> v;
        head = head->next;
        while (head->next != NULL) {
            int curr = head->val;
            int next = head->next->val;
            if (curr>prev && curr>next) {
                v.push_back(index);
            }
            if (curr<prev && curr<next) {
                v.push_back(index);
            }
            prev = head->val;
            head = head->next;
            index++;
        }

        for (int i : v) {
            cout<<i<<" ";
        }

        if (v.size() < 2) {
            return {-1, -1};
        }
        
        int minDist = INT_MAX;
        int maxDist = v[v.size() - 1] - v[0];
        for (int i = 1; i < v.size(); i++) {
            minDist = std::min(minDist,
                v[i] - v[i - 1]);
        }

        return {minDist, maxDist};
    }
};
