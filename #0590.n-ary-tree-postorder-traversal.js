/**
 * // Definition for a _Node.
 * function _Node(val,children) {
 *    this.val = val;
 *    this.children = children;
 * };
 */

/**
 * @param {_Node|null} root
 * @return {number[]}
 */
var postorder = function(root) {
    const stack = root ? [root] : [];
    const results = [];
    while (stack.length) {
        root = stack.pop();
        if(root) {
            stack.push(...root.children);
            results.push(root.val);
        }
    }
    return results.reverse();
};
