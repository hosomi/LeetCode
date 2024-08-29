/**
 * @param {number[][]} stones
 * @return {number}
 */
var removeStones = function(stones) {
    const hashMap = stones.reduce((map, stone, index) => {
        return map.set(index, index);
    }, new Map());

    const unionFind = (value) => {
        const target = hashMap.get(value);
        return target === value ? value : unionFind(target);
    };

    for (let i = 1; i < stones.length; i++) {
        for (let j = i - 1; j >= 0; j--) {
            const [x1, y1] = stones[i];
            const [x2, y2] = stones[j];
            if (x1 !== x2 && y1 !== y2) {
                continue;
            }

            hashMap.set(unionFind(i), unionFind(j));
        }
    }

    let unions = 0;
    hashMap.forEach((value, key) => {
        if (value === key) {
            unions += 1;
        }
    });

    return stones.length - unions;
};
