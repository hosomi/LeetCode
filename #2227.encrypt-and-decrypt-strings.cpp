class Encrypter {
public:
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {

        int size = keys.size();
        for (int i = 0; i < size; ++i) {
            enc[keys[i]] = values[i];
        }

        for (string& w: dictionary) {
            count[encrypt(w)]++;
        }
    }
    
    string encrypt(string s) {

        string result = "";
        for (char c: s) {
        	if (!enc.count(c)) {
                return "";
            }
            result += enc[c];
        }
        return result;
    }
    
    int decrypt(string s) {
        
        return count[s];
    }

private:
    unordered_map<char, string> enc;
    unordered_map<string, int> count;
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */
