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
 */
var FindElements = function(root) {
    this.set = new Set();
    root.val = 0;
    let queue = [root];
    while (queue.length) {
        let curr = queue.pop();
        this.set.add(curr.val);
        if (curr.left) {
            curr.left.val = curr.val * 2 + 1;
            queue.push(curr.left);
        }
        if (curr.right) {
            curr.right.val = curr.val * 2 + 2;
            queue.push(curr.right);
        }
    }
};

/** 
 * @param {number} target
 * @return {boolean}
 */
FindElements.prototype.find = function(target) {
    return this.set.has(target);
};

/** 
 * Your FindElements object will be instantiated and called as such:
 * var obj = new FindElements(root)
 * var param_1 = obj.find(target)
 */
