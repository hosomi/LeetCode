/**
 * @param {number[][]} points
 * @return {number}
 */
var findMinArrowShots = function(points) {
    let count = 0;
    let min = null;
    points.sort((left, right) => left[0] - right[0]);
    for (let [x, y] of points) {
        if (min == null || min < x) {
            count++
            min = y
        } else {
            min = Math.min(min, y);
        }
    }
    return count;
};
