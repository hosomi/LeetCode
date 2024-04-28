/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number[]}
 */
var sumOfDistancesInTree = function(n, edges) {
    let arr = new Array(n);
    for (let i = 0; i < n; i++) {
        arr[i] = new Array();
    }

    for (let e of edges) {
        arr[e[0]].push(e[1]);
        arr[e[1]].push(e[0]);
    }

    let count = new Array(n).fill(1);
    let results = new Array(n).fill(0);
    let dfs1 = function(node, parent) {
        for (let child of arr[node]){
            if (child != parent) {
                dfs1(child, node);
                count[node] += count[child];
                results[node] += results[child] + count[child];
            }
        }
    }

    let dfs2 = function(node, parent) {
        for (let child of arr[node]) {
            if (child != parent) {
                results[child] = n - count[child] + results[node] - count[child];
                dfs2(child, node);
            }
        }
    }

    dfs1(0, -1);
    dfs2(0, -1);
    return results;
};
