/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        if (k == 0) {
            return { target->val };
        }

        unordered_map<TreeNode*,TreeNode*> umap;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* t = q.front();
                q.pop();
                if (t->left != NULL) {
                    q.push(t->left);
                    umap[t->left] = t;
                }

                if (t->right != NULL) {
                    q.push(t->right);
                    umap[t->right] = t;
                }
            }
        }

        unordered_map<TreeNode*,bool> umap2;
        q.push(target);
        umap2[target] = true;
        int d = 0;
        while(!q.empty()) {
            if (d++ == k) {
                break;
            }

            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* t = q.front();
                q.pop();
                if (t->left != NULL && umap2[t->left] == 0) {
                    q.push(t->left);
                    umap2[t->left] = true;
                }

                if (t->right != NULL && umap2[t->right] == 0) {
                    q.push(t->right);
                    umap2[t->right] = true;
                }

                if (umap[t] && umap2[umap[t]]==0) {
                    q.push(umap[t]), umap2[umap[t]] = true;
                }
            }
        }

        vector<int> result;
        while (!q.empty()) {
            int t = q.front()->val;
            result.push_back(t);
            q.pop();
        }
        return result;
    }
};
