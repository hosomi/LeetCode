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
    TreeNode* recoverFromPreorder(string traversal) {

        int size = traversal.size();
        int level;
        int value;
        TreeNode* node;
        stack<TreeNode*> stk;
        for (int i = 0; i < size;) {
            level = 0;
            value = 0;

            for (; traversal[i]=='-' && i < size; i++) {
                level++;
            }

            for (; traversal[i]!='-' && i < size; i++) {
                value = value * 10 + (traversal[i] - '0');
            }

            node = new TreeNode(value);
            while (stk.size() > level) {
                stk.pop();
            }

            if (!stk.empty()) {
                if (!stk.top()->left) {
                    stk.top()->left = node;
                } else {
                    stk.top()->right = node;
                }
            }

            stk.push(node);
        }
        
        while (!stk.empty()) {
            node = stk.top();
            stk.pop();
        }

        return node;
    }
};
