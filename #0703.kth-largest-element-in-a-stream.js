/**
 * @param {number} k
 * @param {number[]} nums
 */
var KthLargest = function(k, nums) {
    this.main = new MinPriorityQueue();
    this.size = k; 
    for (let num of nums) {
        this.add(num);
    }
};

/** 
 * @param {number} val
 * @return {number}
 */
KthLargest.prototype.add = function(val) {
    this.main.enqueue(val);
    if (this.main.size() > this.size) {
        this.main.dequeue();
    }
    return this.main.front().element;
};

/** 
 * Your KthLargest object will be instantiated and called as such:
 * var obj = new KthLargest(k, nums)
 * var param_1 = obj.add(val)
 */
