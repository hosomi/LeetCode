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
 * @param {number} low
 * @param {number} high
 * @return {number}
 */
var rangeSumBST = function(root, low, high) {
    const isInBetween = val => val >= low && val <= high;
    const add = (val, sum) => isInBetween(val) ? sum += val : sum;
    const preorder = (root, sum) => {
        if (!root) {
            return sum;
        }
        return add(root.val, sum)
            + preorder(root.left, sum)
            + preorder(root.right, sum);
    } 
    return preorder(root, 0);
};
