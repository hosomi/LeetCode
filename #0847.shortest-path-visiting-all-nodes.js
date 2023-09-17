/**
 * @param {number[][]} graph
 * @return {number}
 */
var shortestPathLength = function(graph) {
    let length = graph.length;
    let visitedNode = [];
    let queue = [];
    for (let i = 0; i < length; i++) {
        visitedNode.push(new Set([1<<i]));
        queue.push([i, 1<<i]);
    }

    let result = 0;
    while (queue.length > 0) {
        result += 1;
        let newQueue = [];
        for (let qVal of queue) {
            const [node, value] = qVal;
            for (let neighbourNode of graph[node]) {
                let midNode = (1<<neighbourNode)|value;
                if (!visitedNode[neighbourNode].has(midNode)) {
                    if (midNode + 1 === 1<<length) {
                        return result;
                    }
                    visitedNode[neighbourNode].add(midNode);
                    newQueue.push([neighbourNode, midNode]);
                }
            }
        }
        queue = newQueue;
    }
    return 0;
};
