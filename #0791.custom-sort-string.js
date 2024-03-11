/**
 * @param {string} order
 * @param {string} s
 * @return {string}
 */
var customSortString = function(order, s) {
    let m = new Map();
    for (let i = 0; i < order.length; i++) {
        m.set(order[i], i);
    }

    let s2 = s.split("");
    s2.sort((left, right) => (m.get(left) || 0) - (m.get(right) || 0));
    return s2.join("");
};
