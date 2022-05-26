class StockSpanner {
public:
    StockSpanner() {
        
    }
    
    int next(int price) {

        int weight = 1;
        while (!prices.empty() && prices.top() <= price) {
            prices.pop();
            weight += weights.top();
            weights.pop();
        }
        prices.push(price);
        weights.push(weight);
        return weight;
    }

private:
    stack<int> prices;
    stack<int> weights;
};
/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
