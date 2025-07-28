function countMaxOrSubsets(nums: number[]): number {
    function countSubSets(nums, index, curOr, tarOr) {
        if (index == nums.length) {
            return curOr == tarOr ? 1 : 0;
        }

        const withoutCur = countSubSets(nums,index+1,curOr,tarOr);
        const withCur = countSubSets(nums,index+1, curOr|nums[index],tarOr);
        return withCur + withoutCur;
    }

    let maxOr = 0;
    for (let num of nums) {
        maxOr |= num;
    }
    return countSubSets(nums, 0, 0, maxOr);
};
