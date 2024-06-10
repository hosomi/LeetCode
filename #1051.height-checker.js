/**
 * @param {number[]} heights
 * @return {number}
 */
var heightChecker = function(heights) {
    let count = 0;
    let sorted = [...heights].sort((left, right) => left - right);
    for (let i = 0; i < heights.length; i++) {
        if (heights[i] !== sorted[i]) {
            count++;
        }
    } 
    return count;
};
