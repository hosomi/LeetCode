class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        
        priority_queue<int>pq(begin(piles) , end(piles));
        while (k--) {
            int top = pq.top();
            pq.pop();
            top = top / 2 + top % 2;
            pq.push(top);
        }

        int result = 0;
        while (pq.size()) {
            result += pq.top();
            pq.pop();
        }
        return result;
    }
};
