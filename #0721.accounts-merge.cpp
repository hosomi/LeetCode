class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        unordered_map<string, vector<int>> emails;
        for (int i = 0; i < accounts.size(); ++i) {
            for (int j = 1; j < accounts[i].size(); ++j) {
                emails[accounts[i][j]].push_back(i);
            }
        }

        vector<vector<string>> result;
        unordered_set<int> visited;
        for (int i = 0; i < accounts.size(); ++i) {
            unordered_set<string> s;
            find(accounts, i, emails, s, visited);
            if (s.empty()) {
                continue;
            }

            vector<string> account{accounts[i][0]};
            account.insert(account.end(), s.begin(), s.end());
            std::sort(account.begin() + 1, account.end());
            result.push_back(account);
        }
        return result;
    }

private:
    void find(vector<vector<string>>& accounts,
              int index,
              unordered_map<string, vector<int>>& emails,
              unordered_set<string>& s,
              unordered_set<int>& visited) {

        if (visited.count(index)) {
            return;
        }

        visited.insert(index);
        for (int j = 1; j < accounts[index].size(); ++j) {
            const auto& email = accounts[index][j];
            s.insert(email);
            if (emails.count(email) == 0) {
                continue;
            }

            auto indeies(emails[email]);
            emails.erase(email);
            for (auto i : indeies) {
                find(accounts, i, emails, s, visited);
            }
        }
    }
};
