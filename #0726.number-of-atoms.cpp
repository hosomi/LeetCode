class Solution {
public:
    string countOfAtoms(string formula) {

        map<string, int> atoms;
        int cnt = 0;
        int mult = 1;
        stack<int> st;
        for (int i = size(formula) - 1; i >= 0; i--) {
            if (isalpha(formula[i]) and islower(formula[i])) {
                int len = 2;
                i--;
                
                while (i >= 0 and islower(formula[i])) {
                    i--;
                    len++;
                }
                
                string atom = formula.substr(i, len);
                atoms[atom] += max(cnt, 1) * mult;
                cnt = 0;
            } else if (isalpha(formula[i]) and isupper(formula[i])) {
                string atom(1, formula[i]);
                atoms[atom] += max(cnt, 1) * mult;
                cnt = 0;
            } else if (isdigit(formula[i])) {
                cnt = formula[i] - '0';
                int p = 10;
                
                while (i - 1 >= 0 and isdigit(formula[i - 1])) {
                    cnt += p * (formula[--i] - '0');
                    p *= 10;
                }
            } else if (formula[i] == ')') {
                st.push(mult);
                mult *= max(cnt, 1);
                cnt = 0;
            } else {
                mult = st.top();
                st.pop();
            }
        }
        
        string result;
        for (auto [atom, count]: atoms) {
            result += atom;
            
            if (count > 1) {
                result += to_string(count);
            }
        }
        return result;
    }
};
