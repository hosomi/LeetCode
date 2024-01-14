/**
 * @param {string} word1
 * @param {string} word2
 * @return {boolean}
 */
var closeStrings = function(word1, word2) {
    if (word1.length !== word2.length) {
        return false;
    }

    let chars = [{}, {}];
    let notClose = false;
    for (let i = 0; i < word1.length; i ++) {
        if (!word1.includes(word2[i]) || !word2.includes(word1[i])) {
            notClose = true;
            break;
        }

        chars[0][word1[i]] ??= 0;
        chars[0][word1[i]] ++;
        chars[1][word2[i]] ??= 0;
        chars[1][word2[i]] ++;
    }

    if (notClose) {
        return false;
    }

    const values = Object.values(chars[1]);
    Object.values(chars[0]).forEach(n => {
        if (values.indexOf(n) < 0) {
            notClose = true;
            return;
        }

        values.splice(values.indexOf(n), 1);
    })

    return !notClose;
};
