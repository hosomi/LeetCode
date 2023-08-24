/**
 * @param {string[]} words
 * @param {number} maxWidth
 * @return {string[]}
 */
var fullJustify = function(words, maxWidth) {
    let row = [];
    let rowLetters = 0;
    let result = [];
    for (let word of words) {
        if (rowLetters + word.length + row.length > maxWidth) {
            for (let i = 0; i < maxWidth - rowLetters; i++) {
                row[i % (row.length - 1 || 1)] += " ";
            }
            result.push(row.join(""));
            row = [];
            rowLetters = 0;
        }
        row.push(word);
        rowLetters += word.length;
    }
    return result.concat(row.join(" ").padEnd(maxWidth));
};
