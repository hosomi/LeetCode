class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {

        int length = s.length();
        adjList.resize(length);
        visited.resize(length, false);
        for (vector<int> &v:pairs) {
            adjList[v[0]].push_back(v[1]),adjList[v[1]].push_back(v[0]);
        }

        for (int i = 0; i < length; i++) {
            if (!visited[i]) {
                indiceString = "";
                indices.clear();
                dfs(s,i);
                std::sort(indiceString.begin(), indiceString.end());
                std::sort(indices.begin(), indices.end());
                int size = indices.size();
                for (int i = 0; i < size; i++) {
                    s[indices[i]]=indiceString[i];
                }
            }
        }
        return s;
    }

private:
    vector<int> indices;
    vector<bool> visited;
    vector<vector<int>> adjList;
    string indiceString;

    void dfs(string &s,int index) {

        visited[index] = true;
        indices.push_back(index);
        indiceString += s[index];
        for (int &i:adjList[index]) {
            if (!visited[i]) {
               dfs(s, i);
            }
        }
    }
};
