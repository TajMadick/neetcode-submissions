class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int L = 0;
        int R = numbers.size() - 1;

        while (L < R)
        {
            int res = numbers[L] + numbers[R];
            if (res < target) L++;
            else if (res > target) R--;
            else if (res == target) return {L + 1, R + 1};
        } 
    }
};
