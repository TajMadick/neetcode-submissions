class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        dp[2] = nums[0]+nums[2];

        for (int i = 3; i < nums.size(); i++)
        {
            dp[i] = max(dp[i-2] + nums[i], dp[i-3] + nums[i]);
        }

        return max(dp[nums.size()-2], dp[nums.size()-1]);
    }
};
