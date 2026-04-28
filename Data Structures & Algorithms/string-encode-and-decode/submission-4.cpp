class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;

        for (string str: strs)
        {
            encoded += str;
            encoded += "_____";
        }

        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        string str = "";
        int underscoreCount = 0;

        for (char c: s)
        {
            if (c != '_') 
            {
                while(underscoreCount > 0)
                {
                    str.push_back('_');
                    underscoreCount--;
                }
                str.push_back(c);
            }
            else
            {
                underscoreCount ++;

                if (underscoreCount == 5)
                {
                    strs.push_back(str);
                    str = "";
                    underscoreCount = 0;
                }
            }
        }

        return strs;
    }
};
