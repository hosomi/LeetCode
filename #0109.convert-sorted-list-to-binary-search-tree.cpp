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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {

        if (!head) {
            return nullptr;
        }
        
        ListNode *left = head;
        ListNode *right = head;
        ListNode *work = nullptr;
        while (right && right->next) {
            work = left;
            left = left->next;
            right = right->next->next;
        }

        TreeNode* root = new TreeNode(left->val);
        if (left == head) {
            return root;
        }

        work->next = nullptr;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(left->next);
        return root;
    }
};
