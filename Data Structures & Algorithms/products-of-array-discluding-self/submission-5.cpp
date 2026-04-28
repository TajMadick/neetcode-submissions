class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefixSum(nums.size() + 1, 1);
        vector<int> suffixSum(nums.size() + 1, 1);

/*
        for (int num: nums)
        {
            prefixSum.push_back(num * prefixSum.back());
        }
*/

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            suffixSum[i] = nums[i] * suffixSum[i + 1];
        }
        
        for (int i = 0; i < nums.size(); i++)
        {
            prefixSum[i + 1] = nums[i] * prefixSum[i];

            int pref = prefixSum[i];
            int suf = suffixSum[i + 1];

            nums[i] = pref*suf;
        }

        return nums;
    }
};
