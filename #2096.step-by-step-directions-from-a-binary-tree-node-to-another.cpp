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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        
        string startPath;
        helper(root, startValue, startPath);
        string destPath;
        helper(root, destValue, destPath);
        int i = 0, j = 0;
        while (i < startPath.size() 
            && j < destPath.size() 
            && startPath[i] == destPath[j]) {
            i++; j++;
        }
        
        string result = "";
        for (; i<startPath.size(); i++) {
            result += "U";
        }
        for (; j<destPath.size(); j++) {
            result += destPath[j];
        }
        return result;
    }

private:
    bool helper(TreeNode* root, int value, string& partial) {

        if (!root) {
            return false;
        }

        if (root->val == value) {
            return true;
        }

        partial.push_back('L');
        auto result = helper(root->left, value, partial);
        if (result) {
            return result;
        }

        partial.pop_back();
        partial.push_back('R');
        result = helper(root->right, value, partial);
        if (result) {
            return result;
        }

        partial.pop_back();
        return false;
    }
};
