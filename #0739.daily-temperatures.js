/**
 * @param {number[]} temperatures
 * @return {number[]}
 */
var dailyTemperatures = function(temperatures) {
    let stack = [];
    for (let i = 0; i < temperatures.length; i++) {
        while (temperatures[i] > temperatures[stack[0]]) {
            let shifted = stack.shift();
            temperatures[shifted] = i - shifted;
        }
        stack.unshift(i);
    }

    while (stack.length) {
        temperatures[stack.shift()] = 0;
    }
    return temperatures;
};
