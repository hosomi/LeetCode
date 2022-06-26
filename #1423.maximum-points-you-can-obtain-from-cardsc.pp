class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int size = cardPoints.size();
        int accumulate = std::accumulate(cardPoints.begin(),
                                         cardPoints.begin() + size - k, 0);
        int minRemainSum = accumulate;
        int sum = accumulate;
        for (int i = size - k; i < size; i++) {
            accumulate += (cardPoints[i] - cardPoints[i - (size - k)]);
            minRemainSum = min(minRemainSum, accumulate);
            sum += cardPoints[i];
        }
        return sum - minRemainSum;
    }
};
