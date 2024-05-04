/**
 * @param {number[]} people
 * @param {number} limit
 * @return {number}
 */
var numRescueBoats = function(people, limit) {
    let count = 0;
    let left = 0;
    let right = people.length - 1;
    people.sort((left, right) => left - right);
    while (left <= right) {
        if ((people[right] + people[left]) <= limit) {
            left++;
        }
        right--;
        count++;
    }
    return count;
};
