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
 * @param {number[]} queries
 * @return {number[]}
 */
var treeQueries = function(root, queries) {

    const dfs = (node, depth) => {
        if (node === null) {
            return null;
        }
        
        visit(node, depth);
        
        if (node.left) {
            dfs(node.left, depth + 1);
            visit(node, depth);
        }
        
        if (node.right) {
            dfs(node.right, depth + 1);
            visit(node, depth);
        }
    }

    const visit = (n, d) => {
        nodes[tourIndex] = n;
        depth[tourIndex] = d;
        if (start[n.val] === undefined) {
            start[n.val] = tourIndex;
        } else {
            last[n.val] = tourIndex;
        }
        tourIndex = tourIndex + 1;
    }

    let depth = [];
    let nodes = [];
    let start = [];
    let last = [];
    let tourIndex = 0;
    
    dfs(root, 0);
    
    let prefixMax = [];
    let suffixMax = [];
    for (let i = 0; i < depth.length; i++) {
        prefixMax[i] = Math.max(depth[i], (prefixMax[i - 1] ?? -Infinity));
    }
    
    for (let j = depth.length - 1; j >= 0; j--) {
        suffixMax[j] = Math.max(depth[j], (suffixMax[j + 1] ?? -Infinity));
    }
    
    let results = [];
    for (let i = 0; i < queries.length; i++) {
        let q = queries[i];
        let s = start[q];
        let e = last[q] ?? s;
        let bef = prefixMax[s - 1];
        let next = suffixMax[e + 1];
        
        results.push(Math.max(bef, next));
    }
    return results;
};
