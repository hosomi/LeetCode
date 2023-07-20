/**
 * @param {number[]} asteroids
 * @return {number[]}
 */
var asteroidCollision = function(asteroids) {
    let result = [];
    for (let x of asteroids) {
        while (x < 0 && result && result.at(-1) > 0) {
            let y = result.pop();
            if (-x < y) {
                x = y;
            } else if (-x == y) {
                x = 0;
            }
        }

        if (x) {
            result.push(x);
        }
    }
    return result;
};
