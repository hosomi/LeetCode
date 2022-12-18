class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {

        vector<int>timing(n,0);
        stack<int>st;
        vector<int>v;
        int p = -1;
        int id;
        int time;
        bool flag;
        for (auto &log: logs) {
            exclusiveTime(log, id, time, flag);
            if (flag) {
                st.push(time);
                if (++p == v.size()) {
                    v.push_back(0);
                }
            } else {
                int dif = time - st.top() + 1;
                st.pop();
                v[p] += dif;
                timing[id] += dif;
                if (--p != v.size() - 2) {
                    timing[id] -= v.back(); v.pop_back();
                } 
            }
        }
        return timing; 
    }

private:
  void exclusiveTime(string &s, int &id, int &time, bool &flag) {

    id = time = 0;
    int i = 0;
    for (; s[i] != ':'; i++) {
        id = id * 10 + (s[i] - '0');
    }

    if (s[++i] == 's') {
        flag = true;
        i += 6;
    } else {
        flag = false;
        i += 4;
    }

    for (; i != s.size(); i++) {
        time = time * 10 + (s[i] - '0');
    }
  }
};
