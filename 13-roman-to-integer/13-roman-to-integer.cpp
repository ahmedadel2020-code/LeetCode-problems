class Solution {
public:
    int romanToInt(string s) {
    unordered_map<char, int> Table =
    {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    int sum = 0;
    for (int i = 0; i < s.length() - 1; i++)
    {
        if (Table[s[i]] < Table[s[i + 1]])
        {
            sum -= Table[s[i]];
        }
        else
        {
            sum += Table[s[i]];
        }
    }
    sum += Table[s.back()];
    return sum;
    }
};