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
    ListNode* doubleIt(ListNode* head) {
        
        if (!head) {
            return NULL;
        }

        vector<int> nums;
        ListNode *arr1 = head;
        while (arr1) {
            nums.push_back(arr1->val);
            arr1 = arr1->next;
        }

        int n = nums.size() - 1;
        int flag = 0;
        for (int i = n; i >= 0; i--) {
            int doubl = nums[i] * 2 + flag;
            if (doubl > 9) {
                nums[i] = doubl - 10;
                flag = 1;
            } else {
                nums[i] = doubl;
                flag = 0;
            }
        }

        ListNode *arr2 = head;
        if (flag == 1) {
            ListNode* node = new ListNode(1);
            node->next = head;
            head = node;
        }

        int it = 0;
        while (arr2) {
            arr2->val = nums[it++];
            arr2 = arr2->next;
        }
        return head;
    }
};
