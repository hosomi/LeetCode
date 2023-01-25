class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        
        if (node1 == node2) {
            return node1;
        }

        int size = edges.size();
        int n1 = node1;
        int n2 = node2;
        vector<int> vis1(size);
        vector<int> vis2(size);
        int dist = 1;
        while (n1 != -1 && !vis1[n1]) {
            vis1[n1] = dist++;
            n1 = edges[n1];
        }
        dist = 1;

        while (n2 != -1 && !vis2[n2]) {
            vis2[n2] = dist++;
            n2 = edges[n2];
        }

        int max = 1e5;
        int result = -1;
        for (int i = 0 ; i < size; i++) {
            if (vis1[i] && vis2[i]) {
                if (max > std::max(vis1[i], vis2[i])) {
                    result = i;
                    max = std::max(vis1[i], vis2[i]);
                }
            }
        }
        return result;
    }
};
