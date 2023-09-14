/**
 * @param {string[][]} tickets
 * @return {string[]}
 */
var findItinerary = function(tickets) {
    let map = {};
    
    for (const [left, right] of tickets) {
        if (!map[left]) {
            map[left] = [];
        }

        if (!map[right]) {
            map[right] = [];
        }

        map[left].push(right);
        map[left].sort((a, b) => a < b ? 1 : -1);
    }
    
    let arr = [];
    let traverse = (left) => {
        while (map[left].length) {
            traverse(map[left].pop());
        }
        
        arr.push(left);
    };
    traverse("JFK");
    return arr.reverse();
};
