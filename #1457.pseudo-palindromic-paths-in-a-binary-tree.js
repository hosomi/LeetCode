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
var pseudoPalindromicPaths  = function(root) {
    const pseudoPalindromicPaths = (
        node = root, hash = new Set()
    ) => {
        if (!node) {
            return 0;
        }

        const { val } = node;
        const isHasValue = hash.has(val);

        isHasValue ? hash.delete(val) : hash.add(val);
        const left = pseudoPalindromicPaths(node.left, hash);
        const right = pseudoPalindromicPaths(node.right, hash);
        const isPalindromic = hash.size < 2;
        isHasValue ? hash.add(val) : hash.delete(val);
        if (!node.left && !node.right) {
            return isPalindromic ? 1 : 0;
        }
        return left + right;
    };
    return pseudoPalindromicPaths();
};
