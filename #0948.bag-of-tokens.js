/**
 * @param {number[]} tokens
 * @param {number} power
 * @return {number}
 */
var bagOfTokensScore = function(tokens, power) {
    tokens.sort(function(left, right) { return left - right });
    let left = 0;
    let right = tokens.length - 1;
    let score = 0;
    let max = 0;
    while (left <= right && power >= tokens[left]) {
        while (power >= tokens[left] && left <= right) {
            power -= tokens[left];
            score++;
            left++;
        }
        max = Math.max(max, score);
        if (score >= 1 && left < right) {
            power += tokens[right];
            score--;
            right--;
        }
    }
    return max;
};
