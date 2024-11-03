/**
 * @param {string} s
 * @param {string} goal
 * @return {boolean}
 */
var rotateString = function(s, goal) {
    let str = s + s;
    return str.includes(goal) && (s.length === goal.length);
};
