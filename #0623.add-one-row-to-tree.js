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
 * @param {number} val
 * @param {number} depth
 * @return {TreeNode}
 */
var addOneRow = function(root, val, depth) {
    let arr = {val: val, left: root, right: null};
    let nodes = [arr];
    while(--depth > 0) {
        nodes = nodes.reduce((s, node) =>
            s.concat(node.left || [], node.right || []), []);
    }

    nodes.forEach(node =>
        [node.left, node.right] = [
            {val: val, left: node.left, right: null},
            {val: val, left: null, right: node.right}
        ]
    );
    return arr.left;
};
