class Solution {
public:
    struct adderOut {
        bool s;
        bool c;
    };

    int getSum(int a, int b) {
        int sum = 0;
        adderOut fullAdd = {0,0};
        bool ai;
        bool bi;

        for (int i = 0; i < sizeof(int) * 8; i++)
        {
            ai = getBit(a, i);
            bi = getBit(b, i);
            fullAdd = fullAdder(ai, bi, fullAdd.c);
            setBit(sum, i, fullAdd.s);  
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

    adderOut fullAdder(bool ai, bool bi, bool ci)
    {
        adderOut h1 = halfAdder(ai, bi);
        adderOut h2 = halfAdder(h1.s, ci);
        return {h2.s, h1.c || h2.c};
    }

    adderOut halfAdder(bool ai, bool bi)
    {
        // damit man nicht static casten muss != statt xor ^ und && statt &
        return {ai!=bi, ai && bi};
    }
};
