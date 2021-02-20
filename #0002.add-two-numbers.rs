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
    pub fn add_two_numbers(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        
        let (mut cur1, mut cur2, mut digit) = (l1, l2, 0);
        let mut prehead = Some(Box::new(ListNode::new(0)));
        let mut current = prehead.as_mut();
        while cur1.is_some() || cur2.is_some() {
            let mut num = digit;

            if let Some(v) = cur1 {
                num += v.val;
                cur1 = v.next;
            }

            if let Some(v) = cur2 {
                num += v.val;
                cur2 = v.next;
            }

            digit = num / 10;
            let v = current.unwrap();
            v.next = Some(Box::new(ListNode::new(num % 10)));
            current = v.next.as_mut();
        }

        if digit > 0 {
            let v = current.unwrap();
            v.next = Some(Box::new(ListNode::new(digit)));
        }

        prehead.unwrap().next
    }
}
