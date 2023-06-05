/**
 * @param {number[][]} coordinates
 * @return {boolean}
 */
var checkStraightLine = function(coordinates) {
    if (coordinates.length === 2) {
        return true;
    }

    const [x1, y1] = coordinates[0];
    const [x2, y2] = coordinates[1];
    if (x2 - x1 === 0) {
        return coordinates.every(([x]) => x === x1);
    }

    const m = (y2 - y1) / (x2 - x1);
    const b = y1 - m * x1;
    return coordinates.every(([x, y]) => y === m * x + b);
};
