class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {

        stringstream take1(sentence1);
        string word;
        deque<string> q1;
        while(take1>>word) {
            q1.push_back(word);
        }

        stringstream take2(sentence2);
        deque<string> q2;
        while(take2>>word) {
            q2.push_back(word);
        }
        
        while(q1.size() && q2.size() && q1.back() == q2.back()) {
            q1.pop_back();
            q2.pop_back();
        }

        while(q1.size() && q2.size() && q1.front() == q2.front()) {
            q1.pop_front();
            q2.pop_front();
        }
        
        return q1.empty() || q2.empty();
    }
};
