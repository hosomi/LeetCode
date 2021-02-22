// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
// 
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn reverse_k_group(mut head: Option<Box<ListNode>>, k: i32) -> Option<Box<ListNode>> {

        if head.is_none() {
            return head;
        }

        let mut total = 1;
        Self::last(&mut head, Some(&mut total));
        total = total / k * k;


        let mut work = Some(Box::new(ListNode::new(-1)));
        let mut w = &mut work;
        let mut counter = 0;

        while let Some(mut node) = head {
            if counter == total {
                w = Self::last(w, None);
                w.as_mut().unwrap().next = Some(node);
                break;
            }
            head = node.next.take();

            if counter % k == 0 {
                w = Self::last(w, None);
            }
            node.next = w.as_mut().unwrap().next.take();
            w.as_mut().unwrap().next = Some(node);
            counter += 1;
        }
        return work.unwrap().next
    }

    fn last<'a>(mut result: &'a mut Option<Box<ListNode>>, mut counter: Option<&mut i32>) -> 
        &'a mut Option<Box<ListNode>> {

        while result.as_ref().unwrap().next.is_some() {
            result = &mut result.as_mut().unwrap().next;
            counter.as_mut().map(|x| **x += 1);
        }
        return result
    }
}
