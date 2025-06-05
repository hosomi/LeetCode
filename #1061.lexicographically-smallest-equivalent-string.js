/**
 * @param {string} s1
 * @param {string} s2
 * @param {string} baseStr
 * @return {string}
 */
var smallestEquivalentString = function(s1, s2, baseStr) {
    const union = new Map();
    const unionFind = (target) => {
        const value = union.get(target) ?? target;
        return value === target ? value : unionFind(value);
    };

    for (let index = 0; index < s1.length; index++) {
        const a = unionFind(s1[index]);
        const b = unionFind(s2[index]);

        a < b ? union.set(b, a) : union.set(a, b);
    }

    return [...baseStr].reduce((result, str) => {
        return result + unionFind(str);
    }, '');
};
