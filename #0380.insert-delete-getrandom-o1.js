
var RandomizedSet = function() {
    this.set = new Set(); 
};

/** 
 * @param {number} val
 * @return {boolean}
 */
RandomizedSet.prototype.insert = function(val) {
    if (!this.set.has(val)) {
        this.set.add(val);
        return true;
    }
    return false;
};

/** 
 * @param {number} val
 * @return {boolean}
 */
RandomizedSet.prototype.remove = function(val) {
    if (this.set.has(val)) {
        this.set.delete(val);
        return true;
    }
    return false;
}

/**
 * @return {number}
 */
RandomizedSet.prototype.getRandom = function() {
    var it = this.set.values();
    var rand = Math.floor(Math.random() * this.set.size);
    for (var i = 0; i < rand; i++) {
        it.next();
    }
    return it.next().value;
};

/** 
 * Your RandomizedSet object will be instantiated and called as such:
 * var obj = new RandomizedSet()
 * var param_1 = obj.insert(val)
 * var param_2 = obj.remove(val)
 * var param_3 = obj.getRandom()
 */
