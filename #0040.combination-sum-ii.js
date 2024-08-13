/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum2 = function(candidates, target) {
    var buffer = [];
    var result = [];
    candidates.sort((a,b) => a - b);
    search(0, target);
    return result;

    function search(startIdx, target) {
        if (target < 0) {
            return;
        }

        if (target === 0) {
            return result.push(buffer.slice());
        }

        if (startIdx === candidates.length) {
            return;
        }

        for (let i = startIdx; i < candidates.length; i++) {
            if (startIdx < i
                && candidates[i] === candidates[i - 1]) {
                continue;
            }
            buffer.push(candidates[i]);
            search(i+1, target - candidates[i]);
            buffer.pop();

        }
    }
};
