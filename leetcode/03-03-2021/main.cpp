/* Given an array nums containing n distinct numbers in the range [0, n], return
 * the only number in the range that is missing from the array. */

/* Follow up: Could you implement a solution using only O(1) extra space
 * complexity and O(n) runtime complexity? */

/* Solution using sort. */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] + 1 != nums[i + 1]) {
                return nums[i] + 1;
            }
        }
        if(nums[0] != 0) {
            return 0;
        } else {
            return nums.size();
        }
    }
};

/* A faster solution using math */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for(auto& num : nums) {
            sum += num;
        }

        int expectedTotal = (nums.size() * (nums.size() + 1)) / 2;
        return expectedTotal - sum;
    }
};