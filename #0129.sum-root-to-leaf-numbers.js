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
var sumNumbers = function(root) {
    let sumNumbers = (node, sum) => {
        if (!node.left && !node.right) {
            total += sum * 10 + node.val;
        } else {
            if (node.left) {
                sumNumbers(node.left, sum * 10 + node.val);
            }
            if (node.right) {
                sumNumbers(node.right, sum * 10 + node.val);
            }
        }
    }

    let total = 0;
    sumNumbers(root, 0);
    return total;
};
