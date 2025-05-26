/**
 * @param {string} colors
 * @param {number[][]} edges
 * @return {number}
 */
var largestPathValue = function(colors, edges) {
    const n = colors.length;
    let adj = {};
    let inDeg = new Array(n).fill(0); 
    for (let [u, v] of edges) {
        if (!adj[u]) {
            adj[u] = [];
        }
        adj[u].push(v);
        inDeg[v]++;
    }

    let q = [];
    for (let i = 0; i < n; i++) {
        if (inDeg[i] === 0) {
            q.push(i);
        }
    }

    if (q.length == 0) {
        return -1;
    }

    let nodesProcessed = 0, maxColor = 0;
    let nodeColor = new Array(n).fill().map(() => new Array(26).fill(0));

    while (q.length > 0) {
        let node = q.shift();
        nodesProcessed++;
        let colorIndex = colors[node].charCodeAt(0) - 'a'.charCodeAt(0);
        nodeColor[node][colorIndex]++;
        maxColor = Math.max(maxColor, nodeColor[node][colorIndex])

        for (let neighbor of (adj[node] || [])) {
            inDeg[neighbor]--;
            if (inDeg[neighbor] === 0) {
                q.push(neighbor);
            }

            for (let i = 0; i < 26; i++) {
                nodeColor[neighbor][i] = Math.max(nodeColor[neighbor][i], nodeColor[node][i]);
            }
        }
    }

    return nodesProcessed === n ? maxColor : -1; 
};
