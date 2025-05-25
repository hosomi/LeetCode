/**
 * @param {string[]} words
 * @return {number}
 */
var longestPalindrome = function(words) {
    const mapXX = new Map();
    const mapXY = new Map();
    let len = 0;

    for (const word of words) {
        if (word[0] === word[1]) {
            mapXX.set(word, (mapXX.get(word) || 0) + 1);
        } else {
            mapXY.set(word, (mapXY.get(word) || 0) + 1);
        }
    }

    // XX
    let isOdd = false;
    for (const key of mapXX.keys()) {
        const count = mapXX.get(key);
        if (count % 2 === 1) {
            if (!isOdd) {
                isOdd = true;
                len += 1;
            }
            len += (count - 1);
        } else {
            len += count;
        }
    }

    for (const key of mapXY.keys()) {
        const count = mapXY.get(key);
        const pair = key[1] + key[0];
        const pairCount = mapXY.get(pair) || 0;
        if (pairCount > 0) {
            const possiblePairs = Math.min(count, pairCount);
            len += possiblePairs * 2;
            mapXY.set(key, count - possiblePairs);
            mapXY.set(pair, pairCount - possiblePairs);
        }
    }

    return len *2;
};
