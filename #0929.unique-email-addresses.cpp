class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {

        unordered_set<string> result;
        for (auto email : emails) {
            string local;
            string domain;
            int index = 0;
            while (email[index] != '@') {
                index++;
            }
            local = email.substr(0, index);
            domain = email.substr(index + 1);
            string newLocal;
            for (auto l : local) {
                if (l == '+') {
                    break;
                }

                if (l != '.') {
                    newLocal += l;
                }
            }
            result.insert(newLocal + '@' + domain);
        }
        return result.size();
    }
};
