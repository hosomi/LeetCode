function candy(ratings: number[]): number {
    const n = ratings.length;
    let totalCandies = 1;
    let up = 0, down = 0, peak = 0;
    for (let i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1]) {
            up++;
            down = 0;
            peak = up;
            totalCandies += up + 1;
        } else if (ratings[i] === ratings[i - 1]) {
            up = 0;
            down = 0;
            peak = 0;
            totalCandies += 1;
        } else {
            down++;
            up = 0;
            totalCandies += down + (down > peak ? 1 : 0);
        }
    }
    return totalCandies;
};
