/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function(strs) {
    let results = {};
    for (let s of strs) {
        let word = s.split('').sort().join('');
        results[word] ? results[word].push(s) : results[word] = [s];
    }
    return Object.values(results);
};
