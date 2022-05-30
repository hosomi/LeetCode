class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {

        unordered_map<string, int> cp;
        for (auto cpdomain : cpdomains) {
            string s;
            int cnt = 0;
            int num;
            int flag = 0;
            for (auto c:cpdomain) {
                cnt++;
                if (!flag&&c!=' ') {
                    s+=c;
                } else if (!flag) {
                    flag=1;
                    num = std::atoi(s.c_str());
                    cp[cpdomain.substr(cnt)] += num;
                }

                if (flag&&c=='.') {
                    cp[cpdomain.substr(cnt)] += num;
                }
            }
        }

        vector<string> result;
        for (auto c : cp) {
            result.push_back(to_string(c.second) + ' ' + c.first);
        }
        return result;
    }
};
