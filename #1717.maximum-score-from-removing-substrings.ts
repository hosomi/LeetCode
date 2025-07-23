function maximumGain(s: string, x: number, y: number): number {
    let maxPoints = 0;

    const removePattern = (s: string, first: string, second: string, points: number): [string, number] => {
        let stack: string[] = [];
        let score = 0;

        for (let char of s) {
            if (stack.length && stack[stack.length - 1] === first && char === second) {
                stack.pop();
                score += points;
            } else {
                stack.push(char);
            }
        }
        return [stack.join(''), score];
    };

    if (x >= y) {
        let [intermediate, points] = removePattern(s, 'a', 'b', x);
        maxPoints += points;
        [, points] = removePattern(intermediate, 'b', 'a', y);
        maxPoints += points;
    } else {
        let [intermediate, points] = removePattern(s, 'b', 'a', y);
        maxPoints += points;
        [, points] = removePattern(intermediate, 'a', 'b', x);
        maxPoints += points;
    }
    return maxPoints;
};
