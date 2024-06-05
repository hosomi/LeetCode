/**
 * @param {string[]} words
 * @return {string[]}
 */
var commonChars = function(words) {
    let results = [];
    for (const letter of words[0]) {
        if (words.every(w => w.includes(letter))) {
            results.push(letter);
            words = words.map(w => w.replace(letter, ''));
        }
    }
    return results;
};
