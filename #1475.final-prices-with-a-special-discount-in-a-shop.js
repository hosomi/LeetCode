/**
 * @param {number[]} prices
 * @return {number[]}
 */
var finalPrices = function(prices) {
	return prices.map((price, index) => {
		return price - (prices.slice(index + 1).find(dis => dis <= price) || 0);
	})
};
