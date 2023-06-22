/**
 * @param {number[]} prices
 * @param {number} fee
 * @return {number}
 */
var maxProfit = function(prices, fee) {

    let result = 0;
    let buy =-prices[0] - fee;
    for (let i = 1; i < prices.length; i++) {
        if (prices[i] + buy > 0) {
            result += prices[i] + buy;
            buy =-prices[i];
        } else if (buy < -prices[i] - fee) {
            buy =- prices[i] - fee;
        }
    }
    return result;
};
