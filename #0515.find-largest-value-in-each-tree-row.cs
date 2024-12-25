/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    public IList<int> LargestValues(TreeNode root) {

        if (root == null)
        {
            return [];
        }

        Queue<TreeNode> q = [];
        List<int> list = [];
        q.Enqueue(root);
        while (q.Count > 0) {
            var count = q.Count;
            var max = int.MinValue;
            while (count > 0) {
                var temp = q.Dequeue();
                max = Math.Max(max, temp.val);
                if (temp.left != null)
                {
                    q.Enqueue(temp.left);
                }

                if (temp.right != null)
                {
                    q.Enqueue(temp.right);
                }
                count--;
            }
            list.Add(max);
        }
        return list;
    }
}
