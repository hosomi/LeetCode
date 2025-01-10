/**
 * @param {string[]} words1
 * @param {string[]} words2
 * @return {string[]}
 */
var wordSubsets = function(words1, words2) {
    const a = 'a'.charCodeAt(0);
    const getMap = function(word) {
        let len = word.length;
        let map = Array(26).fill(0);
        for (let i = 0; i < len; i++) {
            map[word.charCodeAt(i) - a]++;
        }
        return map;
    };
    
    let umap = getMap(words2[0]);
    for (let i = 1; i < words2.length; i++) {
        let map = getMap(words2[i]);
        for (let j = 0; j < 26; j++) {
            umap[j] = Math.max(umap[j], map[j]);
        }
    }
    
    let results = [];
    for (let i = 0; i < words1.length; i++) {
        let map = getMap(words1[i]);
        let j = 0;
        for (; j < 26; j++) {
            if (map[j] < umap[j]) {
                break;
            }
        }
        if (j === 26) {
            results.push(words1[i]);
        }
    }
    return results;
};
