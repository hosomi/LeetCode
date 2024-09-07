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
    bool isSubPath(ListNode* head, TreeNode* root) {

        function<bool(ListNode*, TreeNode*)> isRootPath;
        isRootPath = [&isRootPath](ListNode* head, TreeNode* root) {
            if (!head) {
                return true;
            }

            if (!root || root->val != head->val) {
                return false;
            }
            
            return isRootPath(head->next,root->left)
                || isRootPath(head->next,root->right);
        };
        return !head
            || (root && (isRootPath(head, root)
            || isSubPath(head, root->left)
            || isSubPath(head, root->right)));

    }
};
