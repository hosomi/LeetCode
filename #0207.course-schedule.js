/**
 * @param {number} numCourses
 * @param {number[][]} prerequisites
 * @return {boolean}
 */
var canFinish = function(numCourses, prerequisites) {
    const graph = Array.from(Array(numCourses), () => []);
    const ranks = Array(numCourses).fill(0);
    prerequisites.forEach(([u, v]) => {
        graph[v].push(u);
        ranks[u]++;
    });

    const queue = [];
    ranks.forEach((r, i) => {
        if (!r) {
            queue.push(i);
        }
    });

    while (queue.length) {
        const f = queue.shift();
        numCourses--;
        graph[f].forEach((neigh) => {
            ranks[neigh]--;
            if (!ranks[neigh]) queue.push(neigh);
        });
    }
    return !numCourses;
};
