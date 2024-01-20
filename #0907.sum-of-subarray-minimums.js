/**
 * @param {number[]} arr
 * @return {number}
 */
var sumSubarrayMins = function(arr) {
    const MOD = 1000000007;
    const stack = [];
    let sum = 0;
    for (let i = 0; i <= arr.length; i++) {
        while (stack.length && (
            i === arr.length ||
            arr[stack[stack.length - 1]] >= arr[i])) {
            const mid = stack.pop();
            const left = stack.length === 0 ?
            -1 : stack[stack.length - 1];
            const right = i;
            const count = (mid - left) * (right - mid) % MOD;
            sum += (count * arr[mid]) % MOD;
            sum %= MOD;
        }
        stack.push(i);
    }
    return sum;
};
