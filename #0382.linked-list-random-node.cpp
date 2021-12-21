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
    Solution(ListNode* head) {
        this->head = head;
    }

    int getRandom() {

        ListNode *cursor = head;
        ListNode *probability = head;
        int count = 0;
        while (cursor != nullptr) {
            if (rand() % (count + 1) == count) {
                probability = cursor;
            }
            cursor = cursor->next;
            count++;
        }
        return probability->val;
    }

private:
    ListNode *head;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
