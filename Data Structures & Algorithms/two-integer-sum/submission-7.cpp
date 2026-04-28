class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap;

        int size = nums.size();

        for (int i = 0; i < size; i++)
        {
            hashmap[nums[i]] = i;
        }

        int difference;

        for (int i = 0; i < size; i++)
        {
            difference = target - nums[i];
            if (hashmap.count(difference) && i != hashmap[difference])
            {
                return {i, hashmap[difference]};
                //vector<int> result = {i, hashmap[difference]};
                //sort(result.begin(), result.end());
                //return result;
            }
        }
    }
};
