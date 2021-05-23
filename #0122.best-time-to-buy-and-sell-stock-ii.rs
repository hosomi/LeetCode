impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {

        let len = prices.len();
        let mut result = 0;
        for i in 1..len {
            if prices[i] > prices[i-1] {
                result += prices[i] - prices[i-1];
            }
        }
        return result;
    }
}
