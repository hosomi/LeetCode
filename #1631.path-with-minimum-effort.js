/**
 * @param {number[][]} heights
 * @return {number}
 */
var minimumEffortPath = function(heights) {
    const queue = new MaxPriorityQueue(
        {
            compare: (left, right) => left.effort - right.effort
        }
    );
    queue.enqueue(createRow(0, 0, 0));
    const directions = [[1, 0], [-1, 0], [0, 1], [0, -1]];

    const isSafe = (i, j) => {
        if (i < 0 || j < 0 || i >= heights.length || j >= heights[0].length) {
            return false;
        }

        return heights[i][j] < Infinity;
    }

    while (!queue.isEmpty()) {
        const {row, col, effort} = queue.dequeue();
        if (row === heights.length - 1 && col === heights[0].length - 1) {
            return effort;
        }

        const prevValue = heights[row][col];
        heights[row][col] = Infinity;
        for (let direction of directions) {
            const newRow = row + direction[0];
            const newCol = col + direction[1];
            if (isSafe(newRow, newCol)) {
                const dif = Math.abs(heights[newRow][newCol] - prevValue);
                const newEffort = Math.max(dif, effort);
                queue.enqueue(createRow(newRow, newCol, newEffort));
            }
        }
    }

    return 0;
};
const createRow = (row, col, effort) => ({ row, col, effort });
