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
var minDepth = function(root) {
    
    if (root == null) {
        return 0;
    }
    
    let queue = [[root, 1]];
    while (queue.length) {
        const [curr, depth] = queue.shift();
        if (curr.left === null && curr.right === null) { 
            return depth;
        }
        
        if (curr.left) {
            queue.push([curr.left, depth + 1]);
        }

        if (curr.right) {
            queue.push([curr.right, depth + 1]);
        }
    }  
    return -1;
};
