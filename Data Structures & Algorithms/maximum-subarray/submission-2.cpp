class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int highestSum = nums[0];
        int sum = 0;
        
        for (int num: nums)
        {
            if (sum < 0) sum = 0;

            sum += num;
            highestSum = max(sum, highestSum);
        }

        return highestSum;
    }
};
