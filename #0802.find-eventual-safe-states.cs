public class Solution {
    public IList<int> EventualSafeNodes(int[][] graph) {

        HashSet<int> terminalNodes = new();
        HashSet<int> visited = new();
        return Enumerable
            .Range(0, graph.Length)
            .Where(IsTerminal)
            .ToArray();

        bool IsTerminal(int node)
        {
            if(!visited.Contains(node))
            {
                visited.Add(node);
                if(graph[node].All(IsTerminal))
                {
                    terminalNodes.Add(node);
                }
            }
            return terminalNodes.Contains(node);
        }
    }
}
