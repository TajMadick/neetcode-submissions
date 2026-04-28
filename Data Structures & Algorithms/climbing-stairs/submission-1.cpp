class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;

        int arr[2] = {1, 1};
        int count = 1;

        while(count < n)
        {
            int temp = arr[0] + arr[1];
            arr[0] = arr[1];
            arr[1] = temp;

            count++;
        }

        return arr[1];
    }
};
