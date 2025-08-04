function totalFruit(fruits: number[]): number {
    const n = fruits.length;
    const fruitCount = new Map<number, number>();
    let left = 0;
    let maxFruits = 0;
    for (let right = 0; right < n; right++) {
        fruitCount.set(fruits[right], (fruitCount.get(fruits[right]) || 0) + 1);
        while (fruitCount.size > 2) {
            const leftFruit = fruits[left];
            fruitCount.set(leftFruit, fruitCount.get(leftFruit)! - 1);
            if (fruitCount.get(leftFruit) === 0) {
                fruitCount.delete(leftFruit);
            }
            left++;
        }

        maxFruits = Math.max(maxFruits, right - left + 1);
    }
    return maxFruits;
};
