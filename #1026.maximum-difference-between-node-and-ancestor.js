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
var maxAncestorDiff = function(root) {
    let result = 0;
    const dfs = (node, {max, min}) => {
        if (!node) {
            return;
        }

        const { val, left, right } = node;
        result = Math.max(result, Math.abs(max - val), Math.abs(min - val));
        max = Math.max(max, val);
        min = Math.min(min, val);
        dfs(left, {max, min});
        dfs(right, {max, min});
    };

    dfs(root, {max: root.val, min: root.val});
    return result;
};
