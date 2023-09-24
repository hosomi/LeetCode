/**
 * @param {number} poured
 * @param {number} query_row
 * @param {number} query_i
 * @return {number}
 */
var champagneTower = function(poured, query_row, query_i) {
    let droped = [[poured]];
    while (droped.length <= query_row) {
        let arr = [];
        let length = droped.length;
        for (let i = 0; i < length + 1; i++) {
            const left = Math.max(0,
                (i === 0 ? 0 :droped[length - 1][i - 1]) - 1) / 2;
            const right= Math.max(0,
                (i === length ? 0 : droped[length - 1][i]) - 1) / 2;
            arr.push(left + right);
        }
        droped.push(arr);
    }
    return droped[query_row][query_i] >= 1 ? 1
        : droped[query_row][query_i];
};
