/**
 * @param {Function[]} functions
 * @param {number} n
 * @return {Function}
 */
var promisePool = async function(functions, n) {

    let index = 0;
    async function callNext() {
        const curFunction = functions[index];
        if (curFunction) {
            index++;
            await curFunction();
            return callNext();
        }
    }
    return Promise.all(new Array(n).fill().map(callNext));
};

/**
 * const sleep = (t) => new Promise(res => setTimeout(res, t));
 * promisePool([() => sleep(500), () => sleep(400)], 1)
 *   .then(console.log) // After 900ms
 */
