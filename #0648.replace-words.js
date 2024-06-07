/**
 * @param {string[]} dictionary
 * @param {string} sentence
 * @return {string}
 */
var replaceWords = function(dictionary, sentence) {
    dictionary.sort((a, b) => a.length - b.length);
    sentence = sentence.split(/\s+/);
    for (let i = 0; i < sentence.length; i++) {
        for (let d of dictionary) {
            if (sentence[i].startsWith(d)) {
                sentence[i] = d;
                break;
            }
        }
    }
    return sentence.join(' ');
};
