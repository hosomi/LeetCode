class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> restoreIp;
        restoreIpAddress(s,4,"",restoreIp);
        return restoreIp;
    }
    void restoreIpAddress(string s,int k,string tmp,vector<string> &restoreIp)
    {
        if (k == 0) {
            if (s.empty()) {
                restoreIp.push_back(tmp);
            }
        } else {
            for (int i = 1; i <= 3; ++i) {
                if (s.size() >= i && isIpV4(s.substr(0,i))) {
                    if (k == 1) {
                        restoreIpAddress(s.substr(i), k-1, tmp + s.substr(0,i), restoreIp);
                    } else {
                        restoreIpAddress(s.substr(i), k-1, tmp + s.substr(0,i) + ".", restoreIp);
                    }
                }
            }
        }
    }

    bool isIpV4(string value)
    {
        if (value.empty() || value.size() > 3 || (value.size() > 1 && value[0] == '0')) {
            return false;
        }
        int m = atoi(value.c_str());
        return m <= 255 && m >= 0;
    }
};
