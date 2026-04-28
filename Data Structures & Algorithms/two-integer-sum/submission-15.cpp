class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> solution;

        for (int i = 0; i < nums.size(); i++)
        {
            solution.insert({target - nums[i], i});
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (solution.count(nums[i]) != 0 && solution[nums[i]] != i)
            {
                vector<int> ret = {i, solution[nums[i]]};
                sort(ret.begin(), ret.end());
                return ret;
            }
        }
    }
};
