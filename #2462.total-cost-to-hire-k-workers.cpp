class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        
        int size = costs.size();
        if (size == 1) {
            return costs[0];
        }

        priority_queue<int, vector<int>, greater<int>> pq1;
        priority_queue<int, vector<int>, greater<int>> pq2;
        int left = 0;
        int right = size-1;
        bool rem = true;
        while (left < candidates) {
            if (left == right){
                pq1.push(costs[left++]);
                rem = false;
            }

            if (left > right) {
                break;
            }

            pq1.push(costs[left++]);
            pq2.push(costs[right--]);
        }

        int count = 0;
        long long result = 0;
        while (count < k) {
            if (left > right) {
                rem = false;
            }

            int p1 = pq1.empty() ? INT_MAX:pq1.top();
            int p2 = pq2.empty() ? INT_MAX:pq2.top();
            cout<<p1<<" "<<p2<<endl;
            bool l = false;
            bool r = false;
            if (p1 <= p2) {
                result += p1;
                pq1.pop();
                l = true;
            } else {
                result += p2;
                pq2.pop();
                r = true;
            }
            
            if (rem) {
                if (l) {
                    pq1.push(costs[left++]);
                } else {
                    pq2.push(costs[right--]);
                }
            }
            count++;
        }
        return result;
    }
};
