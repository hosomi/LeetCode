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
 * @return {TreeNode}
 */
var bstToGst = function(root) {
    let sum = 0; 
    var sums = (node) => {
        if ( node === null) {
            return null;
        }

        sums(node.right);
        sum = sum + node.val;
        node.val = sum;
        sums(node.left)
    };
    sums(root);
    return root;
};
