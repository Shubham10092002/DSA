
//problem statement
Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.


Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
 

Constraints:

1 <= target <= 109
1 <= nums.length <= 105
1 <= nums[i] <= 104
 

//solution


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;

        int prev = 0, curr = 0;
        int ans = INT_MAX;

         sum = accumulate(nums.begin(), nums.end(), 0);

        if(sum < target) {
            return 0;
        }

        sum = 0;

        while (curr < nums.size()) {
            
            while (sum < target && curr < nums.size()) {
                sum += nums[curr];
                curr++;
            }

            ans = min(ans, curr - prev);

            sum -= nums[prev];
            prev++;
        }

        if (sum >= target) {
           
            while (prev < nums.size() && sum >= target) {
                if (sum >= target) {
                    ans = min(ans, curr - prev);
                }
                sum -= nums[prev];
                prev++;
            }
        }

        return ans;
    }
};