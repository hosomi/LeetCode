class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {

		int size = stones.size();
		vector<bool> visited(size, false);

		for (int i = 0; i < size; i++) {
			if (visited[i] == 0) {
                removeStones(stones, visited, i, count);
            }
		}
		return count;
    }

private:
	int count = 0;

	void removeStones(vector<vector<int>>& stones,
        vector<bool>& visited,
        int start, int& count) {

		visited[start] = true;
		vector<int> start_vector = stones[start];
		for (int i = 0; i < stones.size(); i++) {
			if (visited[i] == false 
                && (start_vector[0] == stones[i][0]
                || start_vector[1] == stones[i][1])) {
				count++;
				removeStones(stones, visited, i, count);
      } 
    }
  }
};
