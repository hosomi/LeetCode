class Solution {
public:
    int maximumSwap(int num) {
        
        string n = to_string(num);
        priority_queue<pair<char, int>> q;
        for (int i = 0; i < n.size(); i++) {
            q.push({n[i], i});
        }

        for (int i = 0; i < n.size(); i++) {
            while (q.top().second < i) {
                q.pop();
            }

            if (q.top().first > n[i]) {
                swap(n[i], n[q.top().second]);
                break;
            }
        }
        return stoi(n);
    }
};
