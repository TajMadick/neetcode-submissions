class Solution {
public:
    unordered_map<int, int> hashmap;

    int rob(vector<int>& nums) {
        return max(recurs(nums, 0), recurs(nums, 1));
    }

    int recurs(vector<int>& nums, int index)
    {
        int currentValue = nums[index];

        if (hashmap.count(index)) return hashmap[index];
        if (index >= nums.size()) return 0;
        
        return hashmap[index] = max(recurs(nums, index + 2) + currentValue, 
        recurs(nums, index + 3) + currentValue);
    }
};
