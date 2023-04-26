/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        
        int result = 0;
        for (Employee* e : employees) {
            if (e->id == id) {
                result = e->importance;
                for (int s : e->subordinates) {
                    result += getImportance(employees, s);
                }
                return result;
            }
        }
        return 0;
    }
};
