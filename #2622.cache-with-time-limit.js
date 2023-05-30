
var TimeLimitedCache = function() {
    this.store = new Map();
    this.isExpired = (timestamp) => {
        return timestamp <= new Date().getTime();
    };
};

/** 
 * @param {number} key
 * @param {number} value
 * @param {number} time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */
TimeLimitedCache.prototype.set = function(key, value, duration) {
    const hasKey = this.store.has(key);
    this.store.set(key, [value, new Date().getTime() + duration]);
    return hasKey;
};

/** 
 * @param {number} key
 * @return {number} value associated with key
 */
TimeLimitedCache.prototype.get = function(key) {
    return this.store.has(key)
        && !this.isExpired(this.store.get(key)[1]) ? this.store.get(key)[0] : -1;
};

/** 
 * @return {number} count of non-expired keys
 */
TimeLimitedCache.prototype.count = function() {
    let count = 0;
    for (const val of this.store.values()) {
        if (!this.isExpired(val[1])) {
            count++;
        }
    }
    return count;
};

/**
 * Your TimeLimitedCache object will be instantiated and called as such:
 * var obj = new TimeLimitedCache()
 * obj.set(1, 42, 1000); // false
 * obj.get(1) // 42
 * obj.count() // 1
 */
