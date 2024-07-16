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
 * @param {number} startValue
 * @param {number} destValue
 * @return {string}
 */
var getDirections = function(root, startValue, destValue) {
    let a;
    let b;
    let i = 0;
    const go = (node, route) => {
        if (node.val === startValue) {
            a = [...route];
        }

        if (node.val === destValue) {
            b = [...route];
        }

        if (node.left !== null) {
            route.push("L");
            go(node.left, route);
            route.pop();
        }

        if (node.right !== null) {
            route.push("R");
            go(node.right, route);
            route.pop();
        }
    }

    go(root, []);

    while (a[i]&&b[i]&&a[i] === b[i]) {
        i++;
    }

    return "U".repeat(a.length - i) + b.join("").slice(i);
};
