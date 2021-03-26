/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode RotateRight(ListNode head, int k) {

        if (head == null || head.next == null) {
            return head;
        }

        List<ListNode> ln = new List<ListNode>();
        while (head != null)
        {
            ln.Add(head);
            head = head.next;
        }

        k = k % ln.Count;
        int index = k == 0 ? 0 : ln.Count - k;
        if (index > 0)
        {
            ln[index -1].next = null;
            ln[ln.Count -1].next = ln[0];
        }

        return ln[index];
    }
}
