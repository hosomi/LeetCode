/**
 * @param {number[][]} graph
 * @return {number[]}
 */
var eventualSafeNodes = function(graph) {
    let result = [];
    let nodeVisited = {};
    
    for (let node = 0; node < graph.length; node++) {
        if (isNodeSafeToVisit(graph, node, nodeVisited)) {
            result.push(node);
        }
    }
    return result.sort((a,b) => a - b);
};

function isNodeSafeToVisit(graph, node, visited) {
    if (visited[node] === true) {
        return false;
    }

    if (visited[node] === "safeNode") {
        return true;
    }
    
    visited[node] = true;
    
    for (let i = 0; i < graph[node].length; i++) {
        if (!isNodeSafeToVisit(graph, graph[node][i], visited)) {
            return false;
        }
    }

    visited[node] = "safeNode";
    return true;
}
