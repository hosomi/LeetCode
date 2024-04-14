/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var sumOfLeftLeaves = function(root) {
    if (root == null) {
        return 0;
    }

    let result = 0;
    function sumOfLeftLeaves(root , isLeft) {
        if (isLeft && !root.left && !root.right) {
            result += root.val;
        }

        if (root.left) {
            sumOfLeftLeaves(root.left , true);
        }

        if (root.right) {
            sumOfLeftLeaves(root.right , false);
        }
    }

    sumOfLeftLeaves(root , false);
    return result;
};
