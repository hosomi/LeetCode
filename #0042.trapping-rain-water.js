/**
 * @param {number[]} height
 * @return {number}
 */
var trap = function(height) {
    let i = 0;
    let j = height.length - 1;
    let left = 0;
    let right = 0;
    let result = 0;
    while (i < j) {
        if (height[i] < height[j]) {
            left = Math.max(left, height[i]);
            result += left - height[i++];
        } else {
            right = Math.max(right, height[j]);
            result += right - height[j--];
        }
    }
    return result;
};
