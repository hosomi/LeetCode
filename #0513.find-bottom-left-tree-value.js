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
var findBottomLeftValue = function(root) {
    let arr = [];
    findBottomLeftValue(root, 1);
    return arr[arr.length - 1];

    function findBottomLeftValue(node, level) {
        if (node === null) {
            return;
        }
        
        findBottomLeftValue(node.right, level + 1);
        arr[level] = node.val; 
        findBottomLeftValue(node.left, level + 1);
    }
};
