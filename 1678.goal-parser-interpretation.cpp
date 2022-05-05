class Solution {
public:
    string interpret(string command) {

        int size = command.size();
        string result;
        for (int i = 0; i < size; ) {
            if (command[i] == 'G') {
                result += 'G';
                ++i;
                continue;
            }
    
            if (command[i + 1] == ')') {
                result += 'o';
                i += 2;
                continue;
            }
            
            result += "al";
            i += 4;
        }
        return result;
    }
};
