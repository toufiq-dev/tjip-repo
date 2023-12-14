class Solution {
public:
    // TC: O(n) where n = |Employee|
    // SC: O(n)
    unordered_map<int, Employee*> empMap;
    int getImportance(vector<Employee*> employees, int id) {
      for (Employee* emp : employees) {
        empMap[emp->id] = emp;
      }

      return dfs(id);  
    }

private:
    int dfs(int empId) {
        Employee* employee = empMap[empId];
        int totalImportance = employee->importance;

        for (int subId : employee->subordinates) {
            totalImportance += dfs(subId);
        }

        return totalImportance;
    }
};