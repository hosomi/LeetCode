/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root1
 * @param {TreeNode} root2
 * @return {boolean}
 */
var leafSimilar = function(root1, root2) {
    let arr1 = [];
    dfs(root1, arr1);

    let arr2 = [];
    dfs(root2, arr2);
    return arr1.toString() === arr2.toString();
};

let dfs = (node, arr) => {
    if (!node) {
        return;
    }

    if (!node.left && !node.right) {
        arr.push(node.val)
        return
    }

    dfs(node.left, arr);
    dfs(node.right, arr);
};
