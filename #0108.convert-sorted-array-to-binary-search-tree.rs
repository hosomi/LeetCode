// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn sorted_array_to_bst(nums: Vec<i32>) -> Option<Rc<RefCell<TreeNode>>> {
        return Self::binary_search_tree(&nums, 0, nums.len());
    }

    fn binary_search_tree(nums: &Vec<i32>, left: usize, right: usize) -> Option<Rc<RefCell<TreeNode>>> {
        if left >= right {
            None
        } else {
            let middle = left + (right - left) / 2;
            Some(Rc::new(RefCell::new(TreeNode {
                val: nums[middle],
                right: Self::binary_search_tree(nums, middle + 1, right),
                left: Self::binary_search_tree(nums, left, middle)
            })))
        }
    }
}
