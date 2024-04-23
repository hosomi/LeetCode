/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number[]}
 */
var findMinHeightTrees = function(n, edges) {
	if (n === 1) {
        return [0];
    }

	const graphs = edges.reduce((edge, [left, right]) => {
		edge[left] = (edge[left] ?? new Set()).add(right);
		edge[right] = (edge[right] ?? new Set()).add(left);
		return edge;
	}, []);

	let results = graphs.reduce((graph, set, index) => {
		set.size === 1 && graph.push(index);
		return graph;
	}, []);

	while (n > 2) {
		const arr = [];
		n -= results.length;
		results.forEach(node => {
			graphs[node].forEach(value => {
				graphs[value].delete(node);
				graphs[value].size === 1 && arr.push(value);
			});
		});
		results = arr;
	}
	return results;
};
