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
 * @return {number[]}
 */
var largestValues = function(root) {
    let results = new Array();
    
    function helper(root, level){
        if (root == null) {
            return;
        }
        
        if (results[level] == null) { 
            results.push(root.val);
        } else{
            if (results[level] < root.val) { 
                results[level] = root.val;
            }
        }

        helper(root.left, level + 1);
        helper(root.right, level + 1);
    }
    helper(root, 0);
    return results;
};
