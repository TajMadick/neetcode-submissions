class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numbers;

        sort(nums.begin(), nums.end());

        for (int num: nums)
        {
            numbers.insert(num);
        }

        int maxCount = 0;


        for (int i = 0; i < nums.size();)
        {
            for (int j = nums[i], counter = 0; ; j++)
            {
                if (numbers.count(j))
                {
                    i++;
                    counter ++;
                }
                else
                {
                    maxCount = max(counter, maxCount);
                    break;
                }
            }
        }

        return maxCount;
    }
};
