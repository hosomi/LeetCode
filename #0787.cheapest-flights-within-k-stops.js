/**
 * @param {number} n
 * @param {number[][]} flights
 * @param {number} src
 * @param {number} dst
 * @param {number} k
 * @return {number}
 */
var findCheapestPrice = function(n, flights, src, dst, k) {
    let arr = Array(n).fill(Infinity);
    arr[src] = 0;
    for (let i = 0; i < k + 1; i++) {
        let  temp = [...arr];
        for (let [from , to , price] of flights) {
            temp[to] = Math.min(temp[to] , arr[from] + price);
        }
        arr = [...temp];
    }
    return arr[dst] != Infinity ? arr[dst] : -1;
};
