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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {

        int size = nums.size();
        if (size == 0) {
            return NULL;
        }

        if (size == 1) {
            return new TreeNode(nums[0]);
        }
 
        return constructMaxSubtree(nums, 0, size - 1);
    }

private: 
    int findMaxIndex(vector<int> &nums, int left, int right) {

        int index = left;
        for (int i = left; i <= right ; i++) {
            if(nums[i] >= nums[index])
                index = i;               
        }
        return index;
    }
    
    TreeNode* constructMaxSubtree(vector<int>& nums, int left, int right) {

        if (left > right) {
            return NULL;
        }

        int index = findMaxIndex(nums, left, right);        
        TreeNode* root = new TreeNode(nums[index]);
        root->left = constructMaxSubtree(nums, left, index - 1);
        root->right = constructMaxSubtree(nums, index + 1, right);
        return root;
    }
};
