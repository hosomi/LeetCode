/**
 * @param {string} s
 * @return {string}
 */
var frequencySort = function(s) {
    let map = {};
    for(var i = 0; i < s.length; i++) {
        map[s[i]] = map[s[i]] ? map[s[i]] + 1 : 1;
    }

    var keys = Object.keys(map).sort((left, right) => {
        return map[right] - map[left];
    });

    return "".concat(...keys.map((item) => {
        return item.repeat(map[item]);
    }));
};
