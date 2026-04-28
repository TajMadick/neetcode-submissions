class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> solution;
        solution.reserve(nums.size());

        vector<int> prefixSum;
        prefixSum.push_back(1);

        for (int num: nums)
        {
            prefixSum.push_back(num * prefixSum.back());
        }

        vector<int> suffixSum(nums.size() + 1, 1);

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            suffixSum[i] = nums[i] * suffixSum[i + 1];
        }
        
        for (int i = 0; i < nums.size(); i++)
        {
            int pref = prefixSum[i];
            int suf = suffixSum[i + 1];

            solution.push_back(pref*suf);
        }

        return solution;
    }
};
