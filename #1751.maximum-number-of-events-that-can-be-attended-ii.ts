function maxValue(events: number[][], k: number): number {
    events.sort((a,b) => a[0] - b[0]);
    const memo = new Array(events.length).fill(0).map(_ => {
            let d = new Array(k);
            d[0] = 0;
            return d;
    });
 
    const binarySearch = (start:number, startTime:number) => {
        if (start >= events.length) {
            return start;
        }

        let end = events.length;
        while (start < end) {
            const mid = start + ~~((end - start) / 2);
            if (events[mid][0] >= startTime) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return start;
    }

    const helper = (index:number, k_left:number):number => {
        if (index >= events.length) {
            return 0;
        }

        if (memo[index][k_left] != undefined) {
            return memo[index][k_left];
        }

        let pick = events[index][2];
        const nextIndex = binarySearch(index + 1, events[index][1] + 1);
        pick += helper(nextIndex, k_left - 1);

        let dont_pick = helper(index + 1, k_left);
        memo[index][k_left] = Math.max(pick, dont_pick);
        return memo[index][k_left];
    } 
    return helper(0, k);
};
