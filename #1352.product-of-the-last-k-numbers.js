
var ProductOfNumbers = function() {
    this.numbers = [];
    this.length = 0
};

/** 
 * @param {number} num
 * @return {void}
 */
ProductOfNumbers.prototype.add = function(num) {
    this.numbers.push(num);
    this.length++;
};

/** 
 * @param {number} k
 * @return {number}
 */
ProductOfNumbers.prototype.getProduct = function(k) {
    let prod = 1;
    for(let i=this.length-1; i>=0 && k>0; i--){
        prod *= this.numbers[i];
        k--
    }

    return prod;
};

/** 
 * Your ProductOfNumbers object will be instantiated and called as such:
 * var obj = new ProductOfNumbers()
 * obj.add(num)
 * var param_2 = obj.getProduct(k)
 */
