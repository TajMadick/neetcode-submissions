class Solution {
public:
    int getSum(int a, int b) {
        int sum = 0;
        bool ai = getBit(a, 0);
        bool bi = getBit(b, 0);
        setBit(sum, 0, fullAdderSum(ai, bi, 0));
        bool lastCarry = fullAdderCarry(ai, bi, 0);

        for (int i = 1; i < sizeof(int) * 8; i++)
        {
            ai = getBit(a, i);
            bi = getBit(b, i);
            setBit(sum, i, fullAdderSum(ai, bi, lastCarry));  
            lastCarry = fullAdderCarry(ai, bi, lastCarry);
        }

        return sum;
    }

    bool getBit(int x, int i)
    {
        return (x >> i) & 1;
    }

    void setBit(int& x, int i, bool v)
    {
        if (!v) x &= ~(1<<i);
        else x |= (1<<i);
    }

    int fullAdderSum(bool ai, bool bi, bool ci)
    {
        return ai^bi^ci;
    }

    bool fullAdderCarry(bool ai, bool bi, bool ci)
    {
        return ((ai^bi)&ci)|(ai&bi);
    }
};
