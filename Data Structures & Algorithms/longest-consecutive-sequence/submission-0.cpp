class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numbers;

        for (int num: nums)
        {
            numbers.insert(num);
        }

        int maxCount = 0;
 

        for (int num: nums)
        {
            int prevNum = num;
            for (int i = num, counter = 0; ; i++)
            {
                if (numbers.count(i))
                {
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
