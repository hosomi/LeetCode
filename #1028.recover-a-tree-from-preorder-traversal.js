/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {string} traversal
 * @return {TreeNode}
 */
var recoverFromPreorder = function(traversal) {
    const map = {};
    const reg = /((-+|^)(\d+))/g;
    let depth = 0;
    let matches;
    while (matches = reg.exec(traversal)) {
        depth = matches[2].length;
        const curr = new TreeNode(parseInt(matches[3]));
        const parent = map[depth -1];
        if (parent) {
            if (parent.left === null) {
                parent.left = curr;
            } else {
                parent.right = curr;
            }
        }
        map[depth] = curr;
    }
    return map[0];
};
