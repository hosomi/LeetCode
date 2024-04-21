/**
 * @param {number} n
 * @param {number[][]} edges
 * @param {number} source
 * @param {number} destination
 * @return {boolean}
 */
var validPath = function(n, edges, source, destination) {
    const arr1 = Array.from(Array(n), () => new Array());
    for (const [V, W] of edges) {
        arr1[V].push(W);
        arr1[W].push(V);
    }

    const arr2 = new Array(n).fill(false);
    const validPath = (node) => {
        arr2[node] = true;
        for (const neighbor of arr1[node]) {
            if (!arr2[neighbor]) {
                validPath(neighbor);
            }
        }
    };

    validPath(source);
    return arr2[destination];
};
