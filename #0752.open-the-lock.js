/**
 * @param {string[]} deadends
 * @param {string} target
 * @return {number}
 */
var openLock = function(deadends, target) {
    const d = new Set(deadends);
    let queue = new Set(['0000']);
    let otherQueue = new Set([target]);
    const visited = new Set();
    let level = 0;
    while(queue.size > 0 && otherQueue.size > 0) {
        const nextQueue = new Set();
        for (let combo of queue.keys()) {
            if (d.has(combo) || visited.has(combo)) {
                continue;
            }

            if (otherQueue.has(combo)) {
                return level;
            }
            
            visited.add(combo)
            for (let i = 0; i < 4; i++) {
                for (let j = -1; j <=1; j += 2) {
                    const num = (Number(combo[i]) + j + 10) % 10;
                    const newCombo = combo.substring(0, i)
                        + num + combo.substring(i + 1);
                    
                    if (!visited.has(newCombo)) {
                        nextQueue.add(newCombo)
                    }
                }
            }
        }

        level++;
        queue = otherQueue;
        otherQueue = nextQueue;
    }
    return -1;
};
