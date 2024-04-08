class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        
        int i = 0; 
        while (i < students.size()) {
            if (students[0] == sandwiches[0]) {
                students.erase(students.begin());
                sandwiches.erase(sandwiches.begin());
                i = 0;
                continue;
            }

            students.push_back(students[0]);
            students.erase(students.begin());
            i += 1;
        }
        return students.size();
    }
};
