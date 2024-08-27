/**
 * @param {number} n
 * @param {number[][]} edges
 * @param {number[]} succProb
 * @param {number} start_node
 * @param {number} end_node
 * @return {number}
 */
var maxProbability = function(n, edges, succProb, start_node, end_node) {
    const buidGraph = () => {
        const g = {};
        for (let i = 0; i < edges.length; i++) {
            const [from, to] = edges[i];
            g[from] = (g[from] || new Set()).add([to, succProb[i]]);
            g[to] = (g[to] || new Set()).add([from, succProb[i]]);
        }
        return g;
    }

    const g = buidGraph();
    const visited = {};
    const minHeap = new MaxPriorityQueue({priority:(bid) => bid.pathCost});
    minHeap.enqueue({v:start_node, pathCost : 1});
    while (minHeap.size() > 0) {
        const { element : {v, pathCost}} = minHeap.dequeue();
        if (visited[v] !== undefined) {
            visited[v] = Math.max(visited[v], pathCost);
            continue;    
        } else {
            visited[v]=pathCost;
        }

        if (g[v]) {
            for (const [adj, cost] of g[v]) {
                minHeap.enqueue({v : adj, pathCost : pathCost * cost});
            }
        }
    }
    return visited[end_node] || 0;
};
