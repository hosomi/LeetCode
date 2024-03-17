/**
 * @param {number[][]} intervals
 * @param {number[]} newInterval
 * @return {number[][]}
 */
var insert = function(intervals, newInterval) {
    intervals.push(newInterval);
    intervals.sort((a, b) => a[0] - b[0]);

    for (let i = 1; i < intervals.length; i++) {
        const prev = intervals[i - 1];
        const cur = intervals[i];

        if (prev[1] >= cur[0]) {
            intervals[i] = [prev[0], Math.max(prev[1], cur[1])];
            intervals.splice(i - 1, 1);
            i--;
        }
    }
    return intervals;
};
