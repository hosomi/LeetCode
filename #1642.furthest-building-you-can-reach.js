/**
 * @param {number[]} heights
 * @param {number} bricks
 * @param {number} ladders
 * @return {number}
 */
var furthestBuilding = function(heights, bricks, ladders) {
    const pq = new MinPriorityQueue();
    for (let i = 0; i < heights.length - 1; i++) {
        let diff = heights[i+1] - heights[i];
        if (diff < 0) {
            continue;
        }
        
        pq.enqueue(diff);
        if (pq.size() > ladders) {
            bricks -= pq.dequeue().element;
            if (bricks < 0) {
                return i;
            }
        }
    }
    return heights.length - 1;
};
