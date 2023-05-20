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
    int minimumOperations(TreeNode* root) {
        
        if (!root) {
            return 0;
        }

        int swaps = 0;
        queue<TreeNode *>q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> v;
            while (size--) {
                auto p = q.front();
                q.pop();
                v.push_back(p->val);
                if (p->left) {
                    q.push(p->left);
                }

                if (p->right) {
                    q.push(p->right);
                }
            }

            vector<int> temp (v);
            unordered_map<int,int> mp;

            std::sort(temp.begin(), temp.end());
            
            size = temp.size();
            for (int i = 0; i < size; i++) {
                mp[temp[i]] = i;
            }

            for (int i = 0; i < size; i++) {
                if (mp[v[i]] != i) {
                    std::swap(v[i], v[mp[v[i]]]);
                    swaps++;
                    i--;
                }
            }
        }
        return swaps;
    }
};
