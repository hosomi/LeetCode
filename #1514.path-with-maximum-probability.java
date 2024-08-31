class Solution {
    public double maxProbability(int n, int[][] edges, double[] succProb, int start_node, int end_node) {

        Map<Integer, List<int[]>> map = new HashMap<>();
        for (int i = 0; i < edges.length; i++) {
            map.computeIfAbsent(edges[i][0], k -> new ArrayList<>())
                    .add(new int[] { edges[i][1], i });
            map.computeIfAbsent(edges[i][1], k -> new ArrayList<>())
                    .add(new int[] { edges[i][0], i });
        }

        Queue<Integer> q = new LinkedList<>(Arrays.asList(start_node));
        double[] d = new double[n];
        d[start_node] = 1d;
        while (!q.isEmpty()) {
            int top = q.remove();
            for (int[] l : map.getOrDefault(top, Collections.emptyList())) {
                int neig = l[0], idx = l[1];
                double val = d[top] * succProb[idx];
                if (val > d[neig]) {
                    d[neig] = val;
                    q.offer(neig);
                }
            }
        }
        return d[end_node];
    }
}
