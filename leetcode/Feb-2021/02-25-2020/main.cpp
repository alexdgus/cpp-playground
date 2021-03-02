/* Given an integer array nums, you need to find one continuous subarray that if
 * you only sort this subarray in ascending order, then the whole array will be
 * sorted in ascending order. */

/* Return the shortest such subarray and output its length. */

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int maxFound = nums[0];
        int minOutOfOrderIdx = -1;
        int minOutOfOrder = 0;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] >= maxFound) {
                maxFound = nums[i];
            } else {
                if(minOutOfOrderIdx > -1) {
                    minOutOfOrder = min(minOutOfOrder, nums[i]);
                } else {
                    minOutOfOrder = nums[i];
                }
                minOutOfOrderIdx = i;
            }
        }
        if(minOutOfOrderIdx > -1) {
            for(int i = 0; i < nums.size(); i++) {
                if(nums[i] > minOutOfOrder) {
                    return minOutOfOrderIdx - i + 1;
                }
            }
        }
        return 0;
    }
};