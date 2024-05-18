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
var distributeCoins = function(root) {
    let result = 0;
    const move = (node) => {
        if (!node) {
            return 0;
        }
        
        const left = move(node.left);
        const right = move(node.right);
        result += Math.abs(left) + Math.abs(right);
        return left + right + node.val - 1;
    }
    
    move(root);
    return result;
};
