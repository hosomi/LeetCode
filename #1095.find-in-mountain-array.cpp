/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {

        int length = mountainArr.length();
        int left = 0;
        int right = length - 1;
        int peak = -1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        peak = left;
        if (mountainArr.get(peak) == target) {
            return peak;
        }

        int search1 = search(target, mountainArr, 0, peak - 1, true);
        int search2 = search(target, mountainArr, peak + 1, length - 1, false);
        return search1 == -1 ? search2 : search1;
    }

private:
    int search(int target, MountainArray &mountainArr,
               int left, int right, bool isAsc) {

        while (left < right) {
            int mid = left + (right - left) / 2;
            int index = mountainArr.get(mid);
            if (index == target) {
                return mid;
            }
            
            if (index < target) {
                if (isAsc) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            } else {
                if (isAsc) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
        }
        return mountainArr.get(right) == target ? right : -1;
    }
};
