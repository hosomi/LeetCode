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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> result;
        function<void(TreeNode*, int)> depthFirstSearch = [&](TreeNode* tn, int index) {
            if (!tn) {
                return;
            }

            while (result.size() <= index) {
                result.push_back({});
            }

            result[index].push_back(tn->val);      
            depthFirstSearch(tn->right, index + 1);
            depthFirstSearch(tn->left, index + 1);
        };

        depthFirstSearch(root, 0);
        int size = result.size();
        for (int i = 0; i < size; i += 2) {
            std::reverse(begin(result[i]), end(result[i]));
        }
        return result;
    }
};
