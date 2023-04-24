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
class FindElements {
public:
    FindElements(TreeNode* root) {
        
       root->val = 0;
       queue<pair<TreeNode*,int>> q;
       q.push({root, root->val});
       while (!q.empty()) {
            TreeNode *t=q.front().first;
            int v = q.front().second;
            m[v]++;
            q.pop();
            if (t->left) {
                q.push({t->left, 2 * v + 1});
            }

            if (t->right) {
                q.push({t->right, 2 * v + 2});
            }
       }
    }
    
    bool find(int target) {
        
        return m[target];
    }

private:
     map<int,int> m;
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
