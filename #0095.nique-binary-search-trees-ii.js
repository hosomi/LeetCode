/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {number} n
 * @return {TreeNode[]}
 */
var generateTrees = function(n) {
  const func = (start, end) => 
      start <= end ? Array.from({ length: end - start + 1 }, (_, i) => 
      i + start).reduce((a, elem) => 
      func(start, elem - 1).reduce((a, x) => 
      func(elem + 1, end).reduce((a, y) => 
      [...a, new TreeNode(elem, x, y)], a), a), []) : [null]
  ;
  return func(1, n);
};
