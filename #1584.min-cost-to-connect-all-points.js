/**
 * @param {number[][]} points
 * @return {number}
 */
var minCostConnectPoints = function(points) {
    let length = points.length;
    let counter = 0;
    let i = 0;
    let graph = new Array(length).fill(10000000);
    let result = 0;
    while (++counter < length) {
        graph[i] = Number.MAX_SAFE_INTEGER;
        let min_j = i;
        for (let j = 0; j < length; ++j) {
            if (graph[j] != Number.MAX_SAFE_INTEGER) {
                graph[j] = Math.min(graph[j],
                    Math.abs(points[i][0] - points[j][0]) +
                        Math.abs(points[i][1] - points[j][1])
                    );
                min_j = graph[j] < graph[min_j] ? j : min_j;
            }
        }
        result += graph[min_j];
        i = min_j;
    }
    return result;
};
