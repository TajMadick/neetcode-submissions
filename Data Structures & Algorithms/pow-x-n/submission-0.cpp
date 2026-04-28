class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0)
        {
            x = 1/x;
            n = n * -1;
        }
        if (n == 1) return x;

        return x * myPow(x, n-1);
    }
};
