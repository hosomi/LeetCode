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
        ListNode* mergeKLists(vector<ListNode*>& lists) {

            if (lists.size() == 0) {
                return nullptr;
            }
            
            ListNode* ln = new ListNode(0);
            ListNode* lnnext = ln;
            
            priority_queue<tp, vector<tp>, greater<tp>> pq;
            
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i]) {
                    pq.push(make_pair(lists[i]->val,i));
                }
            }
            
            while (!pq.empty()) {
                auto pqtop = pq.top();
                pq.pop();

                lnnext->next = new ListNode(pqtop.first);
                lnnext = lnnext->next;

                auto vnext = lists[pqtop.second]->next;
                lists[pqtop.second] = lists[pqtop.second]->next;
                if (vnext) {
                    pq.push(make_pair(vnext->val, pqtop.second));
                }
            }
            return ln->next;
        }

    private:
        typedef pair<int, int> tp;

};
