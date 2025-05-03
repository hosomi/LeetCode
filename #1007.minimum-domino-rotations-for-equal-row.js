/**
 * @param {number[]} tops
 * @param {number[]} bottoms
 * @return {number}
 */
var minDominoRotations = function(tops, bottoms) {
    const numberOfA = new Array(7).fill(0);
    const numberOfB = new Array(7).fill(0);
    const same = new Array(7).fill(0);
    for (let i = 0; i < tops.length; i++) {
        numberOfA[tops[i]]++;
        numberOfB[bottoms[i]]++;
        if (tops[i] == bottoms[i]) {
            same[tops[i]]++;
        }
    }
    for (let i = 1; i <= 6; i++) {
        if (numberOfA[i] + numberOfB[i] - same[i] == tops.length) {
            return Math.min(numberOfA[i] - same[i],
                numberOfB[i] - same[i]);
        }
    }
    return -1;
};
